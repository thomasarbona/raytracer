/*
** my_intlen.c for my in /home/arbona/Projects/libs/lib/my/src/math/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  8 10:12:10 2016 Thomas Arbona
** Last update Tue Nov  8 18:06:18 2016 Thomas Arbona
*/

int	my_intlen(int number)
{
  int	count;

  count = 0;
  if (number == 0)
    return (1);
  while (number != 0)
    {
      number /= 10;
      count += 1;
    }
  return (count);
}

int	my_l_intlen(long int number)
{
  int	count;

  count = 0;
  if (number == 0)
    return (1);
  while (number != 0)
    {
      number /= 10;
      count += 1;
    }
  return (count);
}

int	my_ll_intlen(long long int number)
{
  int	count;

  count = 0;
  if (number == 0)
    return (1);
  while (number != 0)
    {
      number /= 10;
      count += 1;
    }
  return (count);
}
