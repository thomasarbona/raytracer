/*
** lli_to_basestr.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 22:00:47 2016 Thomas ARBONA
** Last update Fri Mar  3 13:28:03 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

static t_ulli	get_power(t_ulli nb, int p)
{
  return ((p < 0) ? 0 :
	  (p == 0) ? 1 :
	  (p == 1) ? nb :
	  nb * get_power(nb, p - 1));
}

char		*lli_to_basestr(t_ulli nb, char *base)
{
  char		*out;
  int		base_div;
  t_ulli	div;
  int		index;
  int		power;

  power = 0;
  index = 0;
  base_div = my_strlen(base);
  while (nb >= get_power(base_div, power))
    power += 1;
  if (!(out = malloc(sizeof(char) * (power + 1))))
    return (NULL);
  out[power] = '\0';
  power -= 1;
  while (power >= 0)
    {
      div = get_power(base_div, power);
      out[index] = base[nb / div];
      nb %= div;
      power -= 1;
      index += 1;
    }
  return (out);
}
