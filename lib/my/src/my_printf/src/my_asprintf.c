/*
** my_asprintf.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Fri Nov 11 23:07:10 2016 Thomas ARBONA
** Last update Fri Mar  3 13:31:07 2017 Thomas ARBONA
*/
#include "../include/fmt.h"

char	*my_vasprintf(const char *format, va_list ap)
{
  return (eval_fmt(format, ap));
}

char		*my_asprintf(const char *format, ...)
{
  char		*out;
  va_list	ap;

  va_start(ap, format);
  out = my_vasprintf(format, ap);
  va_end(ap);
  return (out);
}
