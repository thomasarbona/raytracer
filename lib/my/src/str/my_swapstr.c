/*
** my_swapstr.c for libmy in /home/arbona/CPool/CPool_infinadd/lib/my
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 24 14:09:28 2016 Thomas Arbona
** Last update Mon Oct 24 14:10:27 2016 Thomas Arbona
*/

int	my_swapstr(char **s1, char **s2)
{
  char	*tmp;

  tmp = *s2;
  *s2 = *s1;
  *s1 = tmp;
  return (0);
}
