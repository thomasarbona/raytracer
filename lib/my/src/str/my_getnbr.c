/*
** my_getnbr.c for my_getnbr in /home/arbona/CPool/CPool_Day04
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Thu Oct  6 15:54:40 2016 Thomas Arbona
** Last update Thu Oct 13 18:25:43 2016 Thomas Arbona
*/

static int	is_max(char *str, int iterator)
{
  char		*max;
  int		iterator2;

  max = "2147483648";
  iterator2 = 0;
  while (iterator2 <= 9)
    {
      if (str[iterator + iterator2] != max[iterator2])
	return (0);
      iterator2 += 1;
    }
  return (1);
}

static int	get_sign(char *str, int *iterator, int *is_neg)
{
  while (!('0' <= str[*iterator] && str[*iterator] <= '9'))
    {
      if (str[*iterator] != '+' && str[*iterator] != '-')
	return (0);
      if (str[*iterator] == '-')
	{
	  if (*is_neg == 0)
	    *is_neg = 1;
	  else
	    *is_neg = 0;
	}
      *iterator += 1;
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	iterator;
  int	nbr;
  int	is_neg;

  is_neg = 0;
  iterator = 0;
  nbr = 0;
  get_sign(str, &iterator, &is_neg);
  if (is_max(str, iterator))
    return (-2147483648);
  while ('0' <= str[iterator] && str[iterator] <= '9')
    {
      nbr = nbr * 10 + str[iterator] - 48;
      if (nbr < 0)
	return (0);
      iterator += 1;
    }
  if (is_neg)
    nbr *= -1;
  return (nbr);
}
