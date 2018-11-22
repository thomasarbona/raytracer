/*
** my_int_str.c for my in /home/arbona/Projects/libs/lib/my/src/str/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  8 10:10:44 2016 Thomas Arbona
** Last update Tue Nov  8 18:24:07 2016 Thomas Arbona
*/
#include <stdlib.h>

int	my_u_intlen(int);
int	my_ul_intlen(long int);
int	my_ull_intlen(long long int);

char	*my_u_int_str(unsigned int number)
{
  int		len;
  int		index;
  char		*result;

  len = my_u_intlen(number);
  if (!(result = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  index = len;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = number % 10 + 48;
      number /= 10;
    }
  return (result);
}

char	*my_ul_int_str(unsigned long int number)
{
  int		len;
  int		index;
  char		*result;

  len = my_ul_intlen(number);
  if (!(result = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  index = len;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = number % 10 + 48;
      number /= 10;
    }
  return (result);
}

char	*my_ull_int_str(unsigned long long int number)
{
  int		len;
  int		index;
  char		*result;

  len = my_ull_intlen(number);
  if (!(result = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  index = len;
  result[index--] = '\0';
  while (number != 0)
    {
      result[index] = number % 10 + 48;
      number /= 10;
    }
  return (result);
}
