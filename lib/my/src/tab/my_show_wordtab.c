/*
** my_show_wordtab.c for my_show_wordtab in /home/arbona/CPool/CPool_Day08
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Wed Oct 12 13:17:19 2016 Thomas Arbona
** Last update Wed Oct 12 16:14:32 2016 Thomas Arbona
*/

#include <stdlib.h>

int	my_putstr(char *str);
void	my_putchar(char c);

int	my_show_wordtab(char **tab)
{
  int	iterator;

  iterator = 0;
  while (tab[iterator] != NULL)
    {
      my_putstr(tab[iterator]);
      my_putchar('\n');
      iterator += 1;
    }
  return (0);
}
