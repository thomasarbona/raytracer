/*
** parser.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Tue Nov 15 14:45:57 2016 Thomas ARBONA
** Last update Fri Mar  3 13:30:20 2017 Thomas ARBONA
*/
#include "../../include/fmt.h"

int     parse_arg_idx(char **specs, t_specs_data *sdata)
{
  int   index;

  index = 0;
  while ('0' <= (*specs)[index] &&
	 '9' >= (*specs)[index])
    index += 1;
  if ((*specs)[index] != '$')
    return (sdata->arg_idx = 0);
  sdata->arg_idx = my_getnbr(my_strndup(*specs, index));
  if (sdata->arg_idx != 0)
    *specs += index + 1;
  return (0);
}

int		parse_flags(char **specs, t_specs_data *sdata)
{
  int		index;
  t_spec_flag	*flag;

  index = 0;
  while ((flag = get_spec_flag((*specs)[index]))->type & TYPE_FLAG)
    {
      flag->func(flag->token, sdata);
      index += 1;
    }
  *specs += index;
  return (0);
}

int     parse_width(char **specs, t_specs_data *sdata, t_pfargs *pfargs)
{
  int   index;
  int   in_args;
  char	*str_width;

  index = 0;
  in_args = 0;
  if ((*specs)[0] != '*' &&
      !((*specs)[0] >= '1' && (*specs)[0] <= '9'))
    return (sdata->width = -1);
  if ((*specs)[0] == '*')
    in_args = 1;
  *specs += in_args;
  while ((*specs)[index] >= '0' &&
	 (*specs)[index] <= '9')
    index += 1;
  if ((*specs)[index] == '$' && in_args)
    goto_pfargs(pfargs, my_getnbr(my_strndup(*specs, index)));
  str_width = my_strndup(*specs, index);
  sdata->width = (in_args)
    ? va_arg((((*specs)[index] == '$') ? pfargs->ap_cpy : pfargs->ap), int)
    : my_getnbr(str_width);
  if ((in_args && (*specs)[index] == '$') || !in_args)
    *specs += index + (in_args && (*specs)[index] == '$');
  free(str_width);
  return (0);
}

int	parse_prec(char **specs, t_specs_data *sdata, t_pfargs *pfargs)
{
  int	index;
  int	in_args;
  char	*str_prec;

  index = 0;
  in_args = 0;
  if ((*specs)[0] != '.')
    return (sdata->prec = -1);
  *specs += 1;
  if ((*specs)[0] == '*')
    in_args = 1;
  *specs += in_args;
  while ((*specs)[index] >= '0' &&
	 (*specs)[index] <= '9')
    index += 1;
  if ((*specs)[index] == '$' && in_args)
    goto_pfargs(pfargs, my_getnbr(my_strndup(*specs, index)));
  str_prec = my_strndup(*specs, index);
  sdata->prec = (in_args)
    ? va_arg((((*specs)[index] == '$') ? pfargs->ap_cpy : pfargs->ap), int)
    : my_getnbr(str_prec);
  if ((in_args && (*specs)[index] == '$') || !in_args)
    *specs += index + (in_args && (*specs)[index] == '$');
  free(str_prec);
  return (0);
}

int		parse_modif(char **specs, t_specs_data* sdata)
{
  int		index;
  t_spec_flag	*modif;

  index = 0;
  while ((modif = get_spec_flag((*specs)[index]))->type & TYPE_MODIF)
    {
      modif->func(modif->token, sdata);
      index += 1;
    }
  *specs += index;
  return (0);
}
