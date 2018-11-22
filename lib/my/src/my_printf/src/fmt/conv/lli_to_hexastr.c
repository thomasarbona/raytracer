/*
** lli_to_hexastr.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 01:04:52 2016 Thomas ARBONA
** Last update Fri Mar  3 13:28:28 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

char		*lli_to_hexastr(t_specs_data *sdata, t_pfargs *pfargs)
{
  t_ulli	nb;
  char		*out;
  char		*prec;
  int		len;

  nb = get_nbarg(sdata, pfargs);
  out = lli_to_basestr(nb, (sdata->conv == 'x') ? BASE_HEXA : BASE_HEXA_X);
  if (out[0] == '0' && out[1] == '\0' &&
      sdata->prec == 0)
    out[0] = '\0';
  if (my_strlen(out) < sdata->prec)
    {
      len = sdata->prec - my_strlen(out) + 1;
      if (!(prec = malloc(sizeof(char) * len)))
	return (NULL);
      my_memset(prec, len, '0');
      out = my_str_concat(prec, out);
    }
  if (sdata->flags & ALTFLAG)
    out = my_str_concat(((sdata->conv == 'x') ? "0x" : "0X"), out);
  return (out);
}
