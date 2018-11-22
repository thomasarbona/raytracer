/*
** my_swapchar.c for libmy in /home/arbona/CPool/CPool_infinadd/lib/my
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 24 12:25:30 2016 Thomas Arbona
** Last update Mon Oct 31 10:58:10 2016 Thomas Arbona
*/

int	my_swapchar(char **str, int index1, int index2)
{
  char	tmp;

  tmp = (*str)[index2];
  (*str)[index2] = (*str)[index1];
  (*str)[index1] = tmp;
  return (0);
}
