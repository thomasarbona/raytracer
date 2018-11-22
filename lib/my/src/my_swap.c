/*
** my_swap.c for my_swap in /home/arbona/CPool/CPool_Day04
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Thu Oct  6 08:40:48 2016 Thomas Arbona
** Last update Thu Oct  6 15:35:05 2016 Thomas Arbona
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
  return (0);
}
