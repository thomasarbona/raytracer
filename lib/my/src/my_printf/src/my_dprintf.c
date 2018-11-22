/*
** my_dprintf.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Tue Nov 15 16:05:53 2016 Thomas ARBONA
** Last update Fri Mar  3 13:36:28 2017 Thomas ARBONA
*/
#include "../include/fmt.h"

int		my_vdprintf(int fd, const char *format, va_list ap)
{
  int		bytes;
  char		*out;

  out = eval_fmt(format, ap);
  bytes = write(fd, out, my_strlen(out));
  free(out);
  return (bytes);
}

int		my_dprintf(int fd, const char *format, ...)
{
  va_list	ap;
  int		bytes;

  va_start(ap, format);
  bytes = my_vdprintf(fd, format, ap);
  va_end(ap);
  return (bytes);
}
