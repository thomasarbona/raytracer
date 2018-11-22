/*
** convert_base.c for convert_base in /home/arbona/CPool/CPool_Day08
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Wed Oct 12 17:53:05 2016 Thomas Arbona
** Last update Wed Oct 12 18:56:10 2016 Thomas Arbona
*/

#include <stdlib.h>

int	my_getnbr_base(char *str, char *base);
int	my_strlen(char *str);
int	my_power_rec(int nb, int p);

static char	*str_addchar(char *s1, char c)
{
  char		*result;
  int		iterator;

  iterator = 0;
  result = malloc(sizeof(char) * (my_strlen(s1) + 2));
  while (iterator < my_strlen(s1) + 1)
    {
      if (iterator == my_strlen(s1))
	result[iterator] = c;
      else
	result[iterator] = s1[iterator];
      iterator += 1;
    }
  result[iterator + 1] = '\0';
  return (result);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	nbr_b10;
  char	*result;
  int	base_div;
  int	power;
  int	div;

  result = "";
  power = -1;
  if (my_strlen(base_from) <= 1 || my_strlen(base_to) <= 1)
    return (0);
  nbr_b10 = my_getnbr_base(nbr, base_from);
  base_div = my_strlen(base_to);
  if (nbr_b10 < 0)
    {
      result = str_addchar(result, '-');
      nbr_b10 *= -1;
    }
  while (nbr_b10 >= my_power_rec(base_div, ++ power));
  while (--power >= 0)
    {
      div = my_power_rec(base_div, power);
      result = str_addchar(result, base_to[nbr_b10 / div]);
      nbr_b10 %= div;
    }
  return (result);
}
