/*
** my_putnbr_base.c for my_putnbr_base in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 19:51:27 2016 Thomas Arbona
** Last update Tue Oct 11 01:04:19 2016 Thomas Arbona
*/

void	my_putchar(char c);
int	my_strlen(char *str);
int	my_power_rec(int nb, int p);

int	my_putnbr_base(int nbr, char *base)
{
  int	iterator;
  char	*result;
  int	base_div;
  int	div;
  int	power;

  iterator = 0;
  power = 0;
  base_div = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  while (nbr >= my_power_rec(base_div, power))
    power += 1;
  power -= 1;
  while (power >= 0)
    {
      div = my_power_rec(base_div, power);
      my_putchar(base[nbr / div]);
      nbr %= div;
      power -= 1;
    }
  return (0);
}
