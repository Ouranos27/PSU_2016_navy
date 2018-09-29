/*
** fight.c for fight in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  9 14:34:27 2017 valerian huylebroeck
** Last update Tue Feb 14 14:24:46 2017 philippe kam
*/

#include "navy.h"

int	check_lose(char **pos)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (pos[i])
    {
      while (pos[i][j])
	{
	  if (pos[i][j] > '1' && pos[i][j] < '6')
	    return (0);
	  ++j;
	}
      j = 0;
      ++i;
    }
  return (1);
}

int	check_win(char **pos)
{
  int	i;
  int	k;
  int	j;

  k = 0;
  i = 0;
  j = 0;
  while (pos[i])
    {
      while (pos[i][j])
	if (pos[i][j++] == 'x')
	  ++k;
      j = 0;
      ++i;
    }
  if (k == 14)
    return (1);
  else
    return (0);
}

char	*verif_send(char *line)
{
  char	c;

  if (line[0] <= 'h' && line[0] >= 'a')
      line[0] = line[0] - 32;
  if (line[1] <= 'h' && line[1] >= 'a')
    line[1] =line[1] - 32;
  if (line[0] > 'H' || line[0] < 'A' || line[1] > '8' || line[1] < '1')
    if (line[1] > 'H' || line[1] < 'A' || line[0] > '8' || line[0] < '1')
      {
	my_printf("wrong position\n");
	my_printf("attack:\t");
	return (NULL);
      }
  if (line[1] <= 'H' && line[1] >= 'A')
    {
      c = line[0];
      line[0] = line[1];
      line[1] = c;
    }
  return (line);
}

char	*translation()
{
  char	*cr;
  int	fd;

  fd = 0;
  cr = ft_strnew(14);
  while (fd < 12)
    {
      if (global == 1)
	cr = str_add_char(cr, '1');
      else
	cr = str_add_char(cr, '0');
      pause();
      fd++;
    }
  cr = convert(cr, global);
  my_printf("%s:", cr);
  return (cr);
}

void	fight(char **enemy_pos, char **pos, int ac, int enemy_pid)
{
  char	*line;
  char	*cr;

  while (get_next_line(0, &line))
    {
      if ((line = verif_send(line)) == NULL)
	fight(enemy_pos, pos, ac, enemy_pid);
      client(enemy_pid, my_putnbr_base2(line[0], "01"));
      client(enemy_pid, my_putnbr_base2(line[1], "01"));
      enemy_pos = map_enemy(line, enemy_pos);
      if (ac == 3)
	aff(pos, enemy_pos);
      if (win_or_loose(enemy_pos, pos) == -1)
	break ;
      my_printf("waiting for enemy’s attack...\n");
      pause();
      cr = translation();
      pos = modif_map(cr, pos, enemy_pid);
      if (ac == 2)
	aff(pos, enemy_pos);
      if (win_or_loose(enemy_pos, pos) == -1)
	break ;
      else
	my_printf("attack:\t");
    }
}
