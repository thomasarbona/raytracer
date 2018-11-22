/*
** my_int_str.c for my in /home/arbona/Projects/libs/lib/my/src/str/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  8 10:10:44 2016 Thomas Arbona
** Last update Tue Nov  8 18:03:25 2016 Thomas Arbona
*/
#include <stdlib.h>

int	my_intlen(int);
int	my_l_intlen(long int);
int	my_ll_intlen(long long int);

char	*my_int_str(int number)
{
  int		len;
  int		index;
  int		is_neg;
  char		*result;

  len = my_intlen(number);
  is_neg = (number < 0);
  if (!(result = malloc(sizeof(char *) * (len + is_neg + 1))))
    return (NULL);
  index = len + is_neg;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = (number % 10 < 0)
	? number % 10 * -1
        : number % 10;
      result[index--] += 48;
      number /= 10;
    }
  if (is_neg)
    result[0] = '-';
  return (result);
}

char	*my_l_int_str(long int number)
{
  int		len;
  int		index;
  int		is_neg;
  char		*result;

  len = my_l_intlen(number);
  is_neg = (number < 0);
  if (!(result = malloc(sizeof(char *) * (len + is_neg + 1))))
    return (NULL);
  index = len + is_neg;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = (number % 10 < 0)
	? number % 10 * -1
        : number % 10;
      result[index--] += 48;
      number /= 10;
    }
  if (is_neg)
    result[0] = '-';
  return (result);
}

char	*my_ll_int_str(long long int number)
{
  int		len;
  int		index;
  int		is_neg;
  char		*result;

  len = my_ll_intlen(number);
  is_neg = (number < 0);
  if (!(result = malloc(sizeof(char *) * (len + is_neg + 1))))
    return (NULL);
  index = len + is_neg;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = (number % 10 < 0)
	? number % 10 * -1
        : number % 10;
      result[index--] += 48;
      number /= 10;
    }
  if (is_neg)
    result[0] = '-';
  return (result);
}
