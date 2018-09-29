/*
** signal.c for signal in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  9 15:32:09 2017 valerian huylebroeck
** Last update Sun Feb 19 16:09:53 2017 valerian huylebroeck
*/

#include "navy.h"

int	signal_1(int pid)
{
  if (pid == 0 || kill(pid, SIGUSR1) == -1)
    {
      my_printf("Bad PID\n");
      return (84);
    }
  return (0);
}

void	serveur()
{
  global = 1;
}

void	serveur1()
{
  global = 0;
}
