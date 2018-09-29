/*
** client.c for clinet in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Wed Feb  1 16:57:03 2017 valerian huylebroeck
** Last update Thu Feb  2 14:20:22 2017 valerian huylebroeck
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void	client(int pid, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '0')
	{
	  kill(pid, SIGUSR1);
	  usleep(5000);
	}
      else
	{
	  kill(pid, SIGUSR2);
	  usleep(5000);
	  }
       ++i;
    }
}
