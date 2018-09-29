/*
** main.c for main in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Mon Jan 30 17:37:54 2017 valerian huylebroeck
** Last update Sun Feb 19 16:13:31 2017 valerian huylebroeck
*/

#include "navy.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "printf.h"

char	**l(char **pos)
{
  int	y;
  char	**l;

  y = 0;
  l = malloc(sizeof(char*) * 8);
  while (y < 8)
    l[y++] = init_map();
  l[y] = NULL;
  if (pos == NULL)
    return (l);
  y = 0;
  while (pos[y])
    {
      l = put_boat(pos, y, l, 0);
      ++y;
    }
  return (l);
}

void	test(int sig, siginfo_t *siginfo, void *context)
{
  context = context;
  sig = sig;
  global = siginfo->si_pid;
}

int			start()
{
  struct sigaction      act;

  my_printf("waiting for enemy connexion...\n");
  ft_memset(&act, '\0', sizeof(act));
  act.sa_sigaction = &test;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, NULL);
  pause();
  my_printf("enemy connected\n\n");
  return (global);
}

int	flag(int ac, char **av)
{
  if (ac == 2 && ft_strcmp(av[1], "-h") == 0)
    {
      my_printf("USAGE\n\t\t./navy [first_player_pid] navy_positions\n\n");
      my_printf("DESCRIPTION\n\t\tfirst_player_pid\tonly for the 2nd player, pid of first player.\n");
      my_printf("\t\tnavy_positions\t\tfile representing the positions of the ships.\n");
      return (-1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	enemy_pid;
  char	**pos;
  char	**enemy_pos;

  signal(SIGUSR2, serveur);
  signal(SIGUSR1, serveur1);
  if (flag(ac, av) == -1)
    return (0);
  if ((pos = all_error(ac, av)) == NULL)
    return (84);
  pos = l(pos);
  enemy_pos = l(NULL);
  my_printf("my_pid:\t%i\n", getpid());
  if (ac == 2)
      enemy_pid = start();
  else
    my_printf("successfully connected\n\n");
  aff(pos, enemy_pos);
  if (ac == 2)
    {
      my_printf("attack:\t");
      fight(enemy_pos, pos, ac, enemy_pid);
    }
  enemy_1_play(pos, enemy_pos, ft_atoi(av[1]), ac);
  return (0);
}

char	*convert(char *str, int k)
{
  int	i;
  char	*result;

  i = 0;
  result = ft_strnew(2);
  while (i < 7)
    {
      if (str[i] == '1')
	result[0] = result[0] + my_power_it(2, (6 - i));
      ++i;
    }
  while (str[i])
    {
      if (str[i] == '1')
	result[1] = result[1] + my_power_it(2, (12 - i));
      ++i;
    }
  if (k == 1)
    result[1] = result[1] + 1;
  free(str);
  return (result);
}
