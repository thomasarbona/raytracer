/*
** my_showmem.c for my_showmem in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 22:37:51 2016 Thomas Arbona
** Last update Thu Oct 13 18:22:53 2016 Thomas Arbona
*/

void	my_putchar(char c);
int	my_power_rec(int nb, int p);
int	my_putnbr_base(int nbr, char *base);

static void	my_showmem_addr(int addr)
{
  int		addr_size;

  addr_size = 0;
  while (addr >= my_power_rec(16, addr_size))
    addr_size += 1;
  while (addr_size < 8)
    {
      my_putchar('0');
      addr_size += 1;
    }
  my_putnbr_base(addr, "0123456789abcdef");
  my_putchar(':');
  my_putchar(' ');
  my_putchar(' ');
}

static void	my_showmem_content(char *str, int size)
{
  int		iterator;

  iterator = 0;
  while (iterator < 16)
    {
      if (iterator < size)
	{
	  if (0 <= str[iterator] && str[iterator] <= 31)
	    my_putchar('.');
	  else
	    my_putchar(str[iterator]);
	}
      else
	my_putchar('.');
      iterator += 1;
    }
}

static void	my_showmem_line(char *str, int size, int line)
{
  int		iterator;

  iterator = 0;
  my_showmem_addr(line);
  while (iterator < 16)
    {
      if (iterator < size)
	{
	  if (str[iterator] < 16)
	    my_putchar('0');
	  my_putnbr_base(str[iterator], "0123456789abcdef");
	}
      else
	{
	  my_putchar(' ');
	  my_putchar(' ');
	}
      if (iterator % 2)
	my_putchar(' ');
      iterator += 1;
    }
  my_showmem_content(str, size);
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	iterator;
  int	line;

  iterator = 0;
  while (iterator < size)
    {
      line = (size - iterator > 16) ? 16 : size - iterator;
      my_showmem_line(&str[iterator], line, iterator);
      iterator += 16;
    }
  return (0);
}
