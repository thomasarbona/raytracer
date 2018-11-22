/*
** ptr_to_str.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 09:53:39 2016 Thomas ARBONA
** Last update Fri Mar  3 13:29:13 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

char	*ptr_to_str(t_specs_data *sdata, t_pfargs *pfargs)
{
  void	*ptr;
  char	*out;

  if (sdata->arg_idx > 0)
    goto_pfargs(pfargs, sdata->arg_idx);
  ptr = (sdata->arg_idx > 0)
    ? va_arg(pfargs->ap_cpy, void *)
    : va_arg(pfargs->ap, void *);
  if (ptr == NULL)
    return (my_strdup("(nil)"));
  out = lli_to_basestr((t_ulli)ptr, BASE_HEXA);
  return (my_str_concat("0x", out));
}
