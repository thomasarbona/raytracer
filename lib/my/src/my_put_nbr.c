/*
** my_put_nbr.c for my_put_nbr in /home/arbona/CPool/CPool_Day03
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Wed Oct  5 13:33:13 2016 Thomas Arbona
** Last update Thu Oct 13 18:24:22 2016 Thomas Arbona
*/

void	my_putchar(char c);

static int	get_nb_length(int nb)
{
  int		count;

  count = 0;
  if (nb == 0)
    count = 1;
  while (nb > 0)
    {
      nb /= 10;
      count += 1;
    }
  return (count);
}

static int	get_digit(int nb, int rank)
{
  int		div;
  int		div_iter;
  int		digit;

  div_iter = 0;
  div = 1;
  while (div_iter <= rank)
    {
      div *= 10;
      div_iter += 1;
    }
  digit = nb / div % 10;
  return (digit);
}

static void	display_max()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}

int	my_put_nbr(int nb)
{
  int	nb_length;
  int	iterator;

  if (nb == -2147483648)
    {
      display_max();
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  nb_length = get_nb_length(nb);
  iterator = nb_length - 2;
  while (iterator >= -1)
    {
      my_putchar(get_digit(nb, iterator) + 48);
      iterator -= 1;
    }
  return (0);
}
