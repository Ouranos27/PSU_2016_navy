/*
** vrf_error.c for error in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  9 15:18:40 2017 valerian huylebroeck
** Last update Tue Feb 14 14:26:07 2017 philippe kam
*/

#include "navy.h"

int	win_or_loose(char **enemy_pos, char **pos)
{
  if (check_win(enemy_pos) == 1)
    {
      my_printf("I won\n");
      return (-1);
    }
  else if (check_lose(pos) == 1)
    {
      my_printf("Enemy won\n");
      return (-1);
    }
  return (0);
}

void	enemy_1_play(char **pos, char **enemy_pos, int pid, int ac)
{
  char	*cr;

  my_printf("waiting for enemy’s attack...\n");
  pause();
  cr = translation();
  if (pos[cr[1] - 49][(cr[0] - 65) * 2] == '.')
    {
      my_printf("\tmissed\n\n");
      pos[cr[1] - 49][(cr[0] - 65) * 2] = 'o';
      kill(pid, SIGUSR1);
    }
  else
    {
      my_printf("\thit\n\n");
      pos[cr[1] - 49][(cr[0] - 65) * 2] = 'x';
      kill(pid, SIGUSR2);
    }
  my_printf("attack:\t");
  fight(enemy_pos, pos, ac, pid);
}

int	vrf_pos(char **pos, int i)
{
  char	**b_pos;

  if ((b_pos = malloc(sizeof(char*) * 3)) == NULL || pos[0][0] != '2' ||
      pos[1][0] != '3' || pos[2][0] != '4' || pos[3][0] != '5')
    return (-1);
  while (pos[i])
    {
      if ((b_pos = ft_strsplit(pos[i++], ':')) == NULL)
	return (-1);
      if (b_pos[1][0] > 'H' || b_pos[1][0] < 'A' ||
	  b_pos[2][0] > 'H' || b_pos[2][0] < 'A')
	return (-1);
      if (b_pos[1][1] > '8' || b_pos[1][1] < '1' ||
	  b_pos[2][1] > '8' || b_pos[2][1] < '1')
	return (-1);
      if ((b_pos[1][0] != b_pos[2][0]) && (b_pos[2][0] - b_pos[1][0]) != i)
	return (-1);
      if ((b_pos[1][1] != b_pos[2][1]) && (b_pos[2][1] - b_pos[1][1]) != i)
	return (-1);
      if ((b_pos[1][0] == b_pos[2][0]) && (b_pos[1][1] == b_pos[2][1]))
	return (-1);
    }
  free(b_pos);
  return (0);
}

char	**put_boat(char **pos, int y, char **l, char i)
{
  if (pos[y][3] != pos[y][6])
    while (i < pos[y][0] - 48)
      {
	if (l[pos[y][3] - 49 + i][(pos[y][2] - 65) * 2] != '.')
	  return (NULL);
	l[pos[y][3] - 49 + i++][(pos[y][2] - 65) * 2] = pos[y][0];
      }
  else
    while (i < pos[y][0] - 48)
      {
	if (l[pos[y][3] - 49][(pos[y][2] - 65) * 2 + (i * 2)] != '.')
	  return (NULL);
	l[pos[y][3] - 49][(pos[y][2] - 65) * 2 + (i++ * 2)] = pos[y][0];
      }
  return (l);
}

char	**all_error(int ac, char **av)
{
  int	i;
  char	*line;
  int	fd;
  char	**pos;

  i = 0;
  if (ac == 2)
    fd = open(av[1], O_RDONLY);
  else if (ac == 3)
    fd = open(av[2], O_RDONLY);
  if (fd == -1 || av[1] == NULL || (pos = malloc(sizeof(char*) * 4)) == NULL)
    return (NULL);
  while (get_next_line(fd, &line))
    pos[i++] = line;
  if (i != 4)
    return (NULL);
  pos[i] = NULL;
  if (vrf_pos(pos, 0) == -1 || l(pos) == NULL)
    return (NULL);
  if (ac == 3)
    if (signal_1(ft_atoi(av[1])) == 84)
      return (NULL);
  close(fd);
  return (pos);
}
