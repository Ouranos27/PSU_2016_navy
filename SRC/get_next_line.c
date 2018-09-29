/*
** get_next_line.c for gnl in /home/vhuylebr/Desktop/PSU_2016_navy/SRC
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  2 17:43:54 2017 valerian huylebroeck
** Last update Sun Feb 19 16:08:14 2017 valerian huylebroeck
*/

#include "get_next_line.h"

int	vrf(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      ++i;
    }
  return (-1);
}

int	save_l(char *st_str, int ret, char *str, char **line)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = ft_strjoin(str, st_str);
  str = ft_strdup(tmp);
  free(tmp);
  tmp = NULL;
  str[vrf(str)] = '\0';
  while (st_str[ret] != '\0')
    st_str[i++] = st_str[ret++];
  st_str[i] = '\0';
  *line = ft_strdup(str);
  return (1);
}

int				get_next_line(const int fd, char **line)
{
  static struct struct_gnl	gnl[255];

  if (BUFF_SIZE < 1 || fd < 0 || !(gnl[fd].str = malloc(BUFF_SIZE)))
    return (-1);
  if (gnl[fd].st_str == NULL)
    gnl[fd].st_str = ft_strnew(BUFF_SIZE);
  gnl[fd].str = ft_strdup(gnl[fd].st_str);
  if (vrf(gnl[fd].str) != -1)
    return (save_l(gnl[fd].st_str, vrf(gnl[fd].st_str) + 1, gnl[fd].str, line));
  while ((gnl[fd].size = read(fd, gnl[fd].st_str, BUFF_SIZE)) > 0)
    {
      gnl[fd].st_str[gnl[fd].size] = '\0';
      if (vrf(gnl[fd].st_str) != -1)
	return (save_l(gnl[fd].st_str, vrf(gnl[fd].st_str) + 1, gnl[fd].str, line));
      gnl[fd].str = ft_strjoin(gnl[fd].str, gnl[fd].st_str);
    }
  if (gnl[fd].size == -1)
    return (-1);
  if (gnl[fd].size == 0 && (ft_strlen(gnl[fd].st_str) == 0))
    return (0);
  gnl[fd].st_str = ft_strnew(1);
  *line = ft_strdup(gnl[fd].str);
  return (1);
}
