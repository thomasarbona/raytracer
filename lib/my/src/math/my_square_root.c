/*
** my_square_root.c for my_square_root in /home/arbona/CPool/tmp_day05
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Fri Oct  7 09:26:42 2016 Thomas Arbona
** Last update Fri Oct  7 15:30:18 2016 Thomas Arbona
*/

int	my_square_root(int nb)
{
  int	iterator;

  iterator = 1;
  while (iterator <= 46341 && iterator * iterator < nb)
    iterator += 1;
  if (iterator * iterator == nb)
    return (iterator);
  return (0);
}
