/*
** my_strncpy.c for my_strncpy in /home/arbona/CPool/CPool_Day06
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 10 08:40:14 2016 Thomas Arbona
** Last update Thu Nov  3 16:55:21 2016 Thomas Arbona
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	iterator;

  iterator = 0;
  while (src[iterator] != '\0' && iterator < n)
    {
      dest[iterator] = src[iterator];
      iterator += 1;
    }
  dest[iterator] = '\0';
  return (dest);
}
