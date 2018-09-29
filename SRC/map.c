/*
** map.c for map in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  9 15:07:45 2017 valerian huylebroeck
** Last update Tue Feb 14 14:31:14 2017 philippe kam
*/

#include "navy.h"

void	aff(char **pos1, char **pos2)
{
  my_printf("my positions:\n");
  aff_map(pos1);
  my_printf("enemy's positions:\n");
  aff_map(pos2);
}

char	*init_map()
{
  char	*str;
  int	i;

  str = malloc(14);
  i = 0;
  while (i < 15)
    {
      if (i % 2 == 0)
	str[i] = '.';
      else
	str[i] = ' ';
      ++i;
    }
  str[i] = '\0';
  return (str);
}

void	aff_map(char **line)
{
  my_printf(" |A B C D E F G H\n-+---------------\n");
  my_printf("1|%s\n", line[0]);
  my_printf("2|%s\n", line[1]);
  my_printf("3|%s\n", line[2]);
  my_printf("4|%s\n", line[3]);
  my_printf("5|%s\n", line[4]);
  my_printf("6|%s\n", line[5]);
  my_printf("7|%s\n", line[6]);
  my_printf("8|%s\n\n", line[7]);
}

char	**map_enemy(char *line, char **enemy_pos)
{
  if (global == 1)
    {
      my_printf("%s:\thit\n\n", line);
      enemy_pos[line[1] - 49][(line[0] - 65) * 2] = 'x';
    }
  else
    {
      my_printf("%s:\tmissed\n\n", line);
      enemy_pos[line[1] - 49][(line[0] - 65) * 2] = 'o';
    }
  return (enemy_pos);
}

char	**modif_map(char *cr, char **pos, int enemy_pid)
{
  if (pos[cr[1] - 49][(cr[0] - 65) * 2] == '.' ||
      pos[cr[1] - 49][(cr[0] - 65) * 2] == 'o')
    {
      my_printf("\tmissed\n\n");
      pos[cr[1] - 49][(cr[0] - 65) * 2] = 'o';
      kill(enemy_pid, SIGUSR1);
    }
  else
    {
      my_printf("\thit\n\n");
      pos[cr[1] - 49][(cr[0] - 65) * 2] = 'x';
      kill(enemy_pid, SIGUSR2);
    }
  return (pos);
}
