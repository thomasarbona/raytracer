/*
** char_to_str.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 01:59:28 2016 Thomas ARBONA
** Last update Fri Mar  3 13:27:39 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

char	*char_to_str(t_specs_data *sdata, t_pfargs *pfargs)
{
  char	c;
  char	*cstr;

  if (!(cstr = malloc(sizeof(char) * 2)))
    return (NULL);
  if (sdata->arg_idx > 0)
    goto_pfargs(pfargs, sdata->arg_idx);
  c = (sdata->arg_idx > 0)
    ? va_arg(pfargs->ap_cpy, unsigned int)
    : va_arg(pfargs->ap, unsigned int);
  cstr[0] = c;
  cstr[1] = '\0';
  return (cstr);
}
