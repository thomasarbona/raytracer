/*
** pfargs.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 16:36:01 2016 Thomas ARBONA
** Last update Fri Mar  3 13:30:30 2017 Thomas ARBONA
*/
#include "../../include/fmt.h"

void	init_pfargs(t_pfargs *pfargs, va_list ap)
{
  va_copy(pfargs->ap, ap);
  va_copy(pfargs->ap_cpy, ap);
  va_copy(pfargs->ap_new, ap);
}

void	goto_pfargs(t_pfargs *pfargs, int cursor)
{
  int	index;

  index = 0;
  va_copy(pfargs->ap_cpy, pfargs->ap_new);
  while (index < cursor - 1)
    {
      va_arg(pfargs->ap_cpy, int);
      index += 1;
    }
}
