/*
** lli_to_octstr.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 21:58:04 2016 Thomas ARBONA
** Last update Fri Mar  3 13:28:42 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

char		*lli_to_octstr(t_specs_data *sdata, t_pfargs *pfargs)
{
  t_ulli	nb;
  char		*out;
  char		*prec;
  int		len;

  nb = get_nbarg(sdata, pfargs);
  out = lli_to_basestr(nb, BASE_OCTAL);
  if (nb == 0 && sdata->prec == 0)
    out[0] = '\0';
  if (sdata->flags & ALTFLAG && out[0] != '0')
    out = my_str_concat("0", out);
  if (my_strlen(out) >= sdata->prec)
    return (out);
  len = sdata->prec - my_strlen(out) + 1;
  if (!(prec = malloc(sizeof(char) * len)))
    return (NULL);
  my_memset(prec, len, '0');
  return (my_str_concat(prec, out));
}
