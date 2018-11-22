/*
** my_sort_int_tab.c for my_sort_in_tab in /home/arbona/CPool/CPool_Day04
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Thu Oct  6 17:50:13 2016 Thomas Arbona
** Last update Thu Oct  6 18:59:38 2016 Thomas Arbona
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	iterator;
  int	iterator2;
  int	tmp;

  iterator = 0;
  while (iterator < size)
    {
      iterator2 = iterator;
      while (iterator2 < size)
	{
	  if (tab[iterator] > tab[iterator2])
	    {
	      tmp = tab[iterator2];
	      tab[iterator2] = tab[iterator];
	      tab[iterator] = tmp;
	    }
	  iterator2 += 1;
	}
      iterator += 1;
    }
}
