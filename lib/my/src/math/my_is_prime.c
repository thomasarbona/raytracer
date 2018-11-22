/*
** my_is_prime.c for my_is_prime in /home/arbona/CPool/tmp_day05
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Fri Oct  7 09:38:36 2016 Thomas Arbona
** Last update Fri Oct  7 09:49:25 2016 Thomas Arbona
*/

int	my_is_prime(int nb)
{
  int	iterator;

  iterator = 2;
  if (nb < 2)
    return (0);
  while (iterator < nb)
    {
      if (nb % iterator == 0)
	return (0);
      iterator += 1;
    }
  return (1);
}
