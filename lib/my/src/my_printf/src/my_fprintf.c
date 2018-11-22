/*
** my_sprintf.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Fri Nov 11 23:07:10 2016 Thomas ARBONA
** Last update Fri Mar  3 13:31:42 2017 Thomas ARBONA
*/
#include <stdarg.h>

int	my_vfprintf(char *str, const char *format, va_list ap)
{
  (void)str;
  (void)format;
  (void)ap;
  return (0);
}

int		my_fprintf(char *str, const char *format, ...)
{
  int		bytes;
  va_list	ap;

  va_start(ap, format);
  bytes = my_vfprintf(str, format, ap);
  va_end(ap);
  return (bytes);
}
