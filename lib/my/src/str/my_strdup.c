/*
** my_strdup.c for my_strdup in /home/arbona/CPool/CPool_Day08
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Wed Oct 12 08:05:08 2016 Thomas Arbona
** Last update Sat Oct 15 14:15:41 2016 Thomas Arbona
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strdup(char *src)
{
  char	*dest;
  int	length;
  int	iterator;

  iterator = 0;
  length = my_strlen(src);
  if (!(dest = malloc(sizeof(char) * (length + 1))))
      return NULL;
  while (iterator < length)
    {
      dest[iterator] = src[iterator];
      iterator += 1;
    }
  dest[iterator] = '\0';
  return (dest);
}
