/*
** my_printf.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Tue Nov 15 16:05:53 2016 Thomas ARBONA
** Last update Fri Mar  3 13:31:58 2017 Thomas ARBONA
*/
#include "../include/fmt.h"

int		my_vprintf(const char *format, va_list ap)
{
  int		bytes;

  bytes = my_vdprintf(1, format, ap);
  return (bytes);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		bytes;

  va_start(ap, format);
  bytes = my_vprintf(format, ap);
  va_end(ap);
  return (bytes);
}
