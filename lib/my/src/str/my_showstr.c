/*
** my_showstr.c for my_showstr in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 21:35:57 2016 Thomas Arbona
** Last update Mon Oct 10 21:56:47 2016 Thomas Arbona
*/

void	my_putchar(char c);
int	my_putnbr_base(int nbr, char *base);

int	my_showstr(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (0 <= str[iterator] && str[iterator] <= 31)
	{
	  my_putchar('\\');
	  if (str[iterator] < 16)
	    my_putchar('0');
	  my_putnbr_base(str[iterator], "0123456789abcdef");
	}
      else
	my_putchar(str[iterator]);
      iterator += 1;
    }
  return (0);
}
