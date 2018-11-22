/*
** my_revstr.c for my_revstr in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 08:52:07 2016 Thomas Arbona
** Last update Mon Oct 10 21:57:13 2016 Thomas Arbona
*/

int	my_strlen(char *str);

char	*my_revstr(char *str)
{
  int	cursor1;
  int	cursor2;
  char	tmp;

  cursor1 = 0;
  cursor2 = my_strlen(str) - 1;
  while (cursor2 - cursor1 > 0)
    {
      tmp = str[cursor2];
      str[cursor2] = str[cursor1];
      str[cursor1] = tmp;
      cursor1 += 1;
      cursor2 -= 1;
    }
  return (str);
}
