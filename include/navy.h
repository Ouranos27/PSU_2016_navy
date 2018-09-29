/*
** navy.h for navy in /home/vhuylebr/Desktop/PSU_2016_navy
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Thu Feb  2 17:21:07 2017 valerian huylebroeck
** Last update Sun Feb 19 16:13:11 2017 valerian huylebroeck
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "printf.h"

int     signal_1(int pid);
void    fight(char **enemy_pos, char **pos, int ac, int enemy_pid);
char    *verif_send(char *line);
char    **map_enemy(char *line, char **enemy_pos);
int     win_or_loose(char **enemy_pos, char **pos);
char    **modif_map(char *cr, char **pos, int enemy_pid);
char    *convert(char *str, int k);
char    **all_error(int ac, char **av);
void    enemy_1_play(char **pos, char **enemy_pos, int pid, int ac);
int     start();
void    aff(char **pos1, char **pos2);
void    test(int sig, siginfo_t *siginfo, void *context);
void    aff_map(char **line);
char    **l(char **pos);
char    **put_boat(char **pos, int y, char **l, char i);
void	serveur();
void	serveur1();
char    *init_map();
int     vrf_pos(char **pos, int i);
char	*translation();
char    *my_putnbr_base2(char nbr, char *base);
char    *str_add_char(char *str, char c);
void    client(int pid, char *str);
void    fight(char **enemy_map, char **my_map, int ac, int enem);
char    *convert(char *str, int k);
int	check_lose(char **l);
int	check_win(char **g);
int	global;

#endif /* !NAVY_H_ */
