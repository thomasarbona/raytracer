/*
** lli_to_str.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src/fmt
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 17:39:16 2016 Thomas ARBONA
** Last update Fri Mar  3 13:29:00 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

int	get_outlen(t_ulli nb, int isneg, t_specs_data *sdata)
{
  int	len;

  len = (isneg + ((my_ull_intlen(nb) >= sdata->prec)
		  ? my_ull_intlen(nb)
		  : sdata->prec));
  if (sdata->conv != 'u')
    {
      len += !!(sdata->flags & SIGNFLAG && !isneg) +
	(sdata->flags & BLANKFLAG && !isneg);
    }
  return (len);
}

char	*format_out(char *out, int len, int isneg, t_specs_data *sdata)
{
  if (out[len] == '0' && out[len + 1] == '\0' &&
      sdata->prec == 0)
    out[len] = '\0';
  while (len > 0)
    out[--len] = '0';
  if (sdata->conv != 'u')
    {
      if (isneg)
	out[len] = '-';
      else if (sdata->flags & SIGNFLAG)
	out[len] = '+';
      else if (sdata->flags & BLANKFLAG && sdata->conv != 'u')
	out[len] = ' ';
    }
  return (out);
}

static void	check_neg(t_specs_data *sdata, t_ulli *nb, int *isneg)
{
  if ((sdata->flags & SIGNEDFLAG) && (long long)(*nb) < 0)
    {
      *nb = -(*nb);
      *isneg = 1;
    }
}

char		*lli_to_str(t_specs_data *sdata, t_pfargs *pfargs)
{
  t_ulli	nb;
  int		isneg;
  int		len;
  char		*out;

  isneg = 0;
  nb = get_nbarg(sdata, pfargs);
  check_neg(sdata, &nb, &isneg);
  len = get_outlen(nb, isneg, sdata);
  if (!(out = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  out[len] = '\0';
  len -= 1;
  while (nb >= 10)
    {
      out[len] = (nb % 10) + '0';
      nb /= 10;
      len -= 1;
    }
  out[len] = nb + '0';
  return (format_out(out, len, isneg, sdata));
}
