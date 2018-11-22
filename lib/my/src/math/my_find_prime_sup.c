/*
** my_find_prime_sup.c for my_find_is_prime in /home/arbona/CPool/tmp_day05
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Fri Oct  7 09:53:02 2016 Thomas Arbona
** Last update Tue Oct 11 10:28:51 2016 Thomas Arbona
*/

int	my_is_prime(int nb);

int	my_find_prime_sup(int nb)
{
  while (!my_is_prime(nb))
    nb += 1;
  return (nb);
}
