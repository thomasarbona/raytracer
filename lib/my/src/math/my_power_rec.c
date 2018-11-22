/*
** my_power_rec.c for my_power_rec in /home/arbona/CPool/tmp_day05
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Fri Oct  7 09:12:14 2016 Thomas Arbona
** Last update Fri Oct  7 09:17:51 2016 Thomas Arbona
*/

int	my_power_rec(int nb, int p)
{
  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  if (p == 1)
    return (nb);
  return (nb * my_power_rec(nb, p - 1));
}
