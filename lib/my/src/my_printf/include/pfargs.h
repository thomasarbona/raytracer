/*
** pfargs.h for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 16:25:47 2016 Thomas ARBONA
** Last update Wed Nov 23 18:30:19 2016 Thomas ARBONA
*/
#include <stdarg.h>

#ifndef PFARGS_H_
# define PFARGS_H_

typedef struct	s_pfargs
{
  va_list	ap;
  va_list	ap_cpy;
  va_list	ap_new;
}		t_pfargs;

void		init_pfargs(t_pfargs *, va_list);
void		goto_pfargs(t_pfargs *, int);

#endif /* !PFARGS_H_ */
