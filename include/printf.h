/*
** printf.h for .h in /home/vhuylebr/Desktop/my_prinft.c
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Wed Nov  9 13:25:36 2016 valerian huylebroeck
** Last update Thu Jan 12 15:30:59 2017 valerian huylebroeck
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

int	my_putstr_2(char **str, int a);
int     flag_neg(char c, double ap, int a);
int     flag_e(char c, double ap, int a);
int	my_putSTR(char *str, int a);
int     my_float2(double nb, char c, int a);
int	my_printf(char *str, ...);
int	my_putnbr_float(double n, int a);
int	my_putnbr_float2(double n, char c, int a);
int	my_power_it(int nbr, int pow);
int	my_strlen(char *str);
int	my_putchar(char c, int a);
int	my_putstr(char *str, int a);
int	my_put_nbr(int nb, int a);
int	my_putnbr_base(int c, char *str, int a);
int	next2(char c, va_list ap, int a);
int	next(char *str, va_list ap, int a, int i);
int	my_putnbr_unsig_int(unsigned int i, int a);
int	my_putnbrli(unsigned long long i, char *str, int a);

#endif
