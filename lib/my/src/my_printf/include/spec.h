/*
** spec.h for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 10 20:54:17 2016 Thomas ARBONA
** Last update Wed Nov 23 14:19:59 2016 Thomas ARBONA
*/
#include "pfargs.h"

#ifndef SPEC_H_
# define SPEC_H_

typedef struct	s_specs_data
{
  int		arg_idx;
  int		flags;
  int		width;
  int		prec;
  char		conv;
}		t_specs_data;

typedef struct	s_spec_flag
{
  char		token;
  int		type;
  void		(*func)(char, t_specs_data *);
}		t_spec_flag;

typedef struct	s_spec_conv
{
  char		token;
  int		type;
  char		*(*func)();
}		t_spec_conv;

# define TYPE_FLAG	(1 << 0)
# define TYPE_WIDTH	(1 << 1)
# define TYPE_PREC	(1 << 2)
# define TYPE_MODIF	(1 << 3)
# define TYPE_CONV	(1 << 4)

t_spec_conv	*get_spec_conv(char);
t_spec_flag	*get_spec_flag(char);
char		*eval_specs(char *, t_pfargs *);

#endif /* !SPEC_H_ */
