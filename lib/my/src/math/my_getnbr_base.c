/*
** my_getnbr_base.c for my_getnbr_base in /home/arbona/CPool/CPool_Day06
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 10 21:00:20 2016 Thomas Arbona
** Last update Mon Nov  7 11:17:05 2016 Thomas Arbona
*/

int	my_str_contain(char *, char);
int	my_strlen(char *str);
int	my_power_rec(int nb, int p);

static int	my_findchar(char *str, char c)
{
  int		iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (str[iterator] == c)
	return (iterator);
      iterator += 1;
    }
  return ((str[iterator] == c) ? iterator : -1);
}

static int	get_result(char *str, int iterator, char *base)
{
  int		base_div;
  int		power;
  int		div;
  int		result;

  result = 0;
  base_div = my_strlen(base);
  power = my_strlen(&str[iterator]) - 1;
  while (str[iterator] != '\0')
    {
      div = my_power_rec(base_div, power);
      result += my_findchar(base, str[iterator]) * div;
      iterator += 1;
      power -= 1;
    }
  return (result);
}

int	my_getnbr_base(char *str, char *base)
{
  int	power;
  int	iterator;
  int	result;
  int	base_div;
  int	div;
  int	sign;

  base_div = my_strlen(base);
  iterator = 0;
  sign = 1;
  if (base_div <= 1)
    return (0);
  while (my_str_contain(base, str[iterator]) == -1)
    {
      if (str[iterator] != '-' && str[iterator] != '+')
	return (0);
      else if (str[iterator] == '-')
	sign *= -1;
      iterator += 1;
    }
  result = get_result(str, iterator, base);
  return (sign * result);
}
