/*
** my_intlen.c for my in /home/arbona/Projects/libs/lib/my/src/math/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  8 10:12:10 2016 Thomas Arbona
** Last update Tue Nov  8 18:08:50 2016 Thomas Arbona
*/

int	my_u_intlen(unsigned int number)
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

int	my_ul_intlen(unsigned long int number)
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

int	my_ull_intlen(unsigned long long int number)
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
