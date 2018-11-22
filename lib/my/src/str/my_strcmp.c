/*
** my_strcmp.c for my_strcmp in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 10:23:27 2016 Thomas Arbona
** Last update Tue Oct 11 14:27:49 2016 Thomas Arbona
*/

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2)
{
  int	iterator;

  iterator = 0;
  while (s1[iterator] != '\0' && s2[iterator] != '\0')
    {
      if (s1[iterator] != s2[iterator])
	return ((s1[iterator] - s2[iterator] < 0) ? -1 : 1);
      iterator += 1;
    }
  if (s1[iterator] != s2[iterator])
    return ((s1[iterator] - s2[iterator] < 0) ? -1 : 1);
  return (0);
}
