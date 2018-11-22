/*
** my_strtof.c for my in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 13 14:01:42 2017 Thomas ARBONA
** Last update Mon Mar 13 14:23:35 2017 Thomas ARBONA
*/

static int	get_power(int zero)
{
  int		pow;
  int		index;

  pow = 1;
  index = 0;
  while (index < zero)
    {
      pow *= 10;
      index += 1;
    }
  return (pow);
}

static void	compute_decimal(double *f, char *str, int index)
{
  int		index2;

  index2 = 0;
  if (str[index] != '.')
    return;
  index += 1;
  while (('0' <= str[index] && str[index] <= '9') &&
	 str[index] != 0)
    {
      *f += (str[index] - 48) / (float)get_power(index2 + 1);
      index += 1;
      index2 += 1;
    }
}

double		my_atof(char *str)
{
  double	f;
  int		index;
  int		sign;

  index = 0;
  f = 0.;
  sign = 0;
  while ((str[index] == '-' || str[index] == '+') && str[index] != 0)
    {
      if (str[index] == '-')
	sign = !sign;
      index += 1;
    }
  while (('0' <= str[index] && str[index] <= '9') &&
	 str[index] != '.' && str[index] != 0)
    {
      f = f * 10. + (str[index] - 48);
      index += 1;
    }
  compute_decimal(&f, str, index);
  if (sign)
    f *= -1;
  return (f);
}
