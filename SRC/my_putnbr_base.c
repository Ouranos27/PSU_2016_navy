/*
** my_putnbr_base.c for getnbr_base in /home/vhuylebr/rendu/CPool_Day06
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Mon Oct 10 09:54:47 2016 valerian huylebroeck
** Last update Sun Feb 19 16:13:55 2017 valerian huylebroeck
*/

#include <stdlib.h>
#include "libft.h"

char	*str_add_char(char *str, char c)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = ft_strnew(8);
  while (str[i])
    {
      tmp[i] = str[i];
      ++i;
    }
  tmp[i++] = c;
  tmp[i] = '\0';
  return (tmp);
}

char	*my_putnbr_base2(char nbr, char *base)
{
  int	size_base;
  int	div;
  int	result;
  char	*str;

  div = 1;
  str = ft_strnew(8);
  size_base = ft_strlen(base);
  if (nbr < 0)
    {
      ft_putchar('-');
      nbr = nbr * -1;
    }
  while (nbr / div >= size_base)
    div = div * size_base;
  while (div > 0)
    {
      result = (nbr / div) % size_base;
      str = str_add_char(str, base[result]);
      div = div / size_base;
    }
  return (str);
}
