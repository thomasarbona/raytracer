/*
** my_strndup.c for libmy in /home/arbona/CPool/libmy/lib/my
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Fri Oct 14 17:50:23 2016 Thomas Arbona
** Last update Fri Oct 14 17:54:25 2016 Thomas Arbona
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strndup(char *src, int n)
{
  char	*dest;
  int	iterator;

  iterator = 0;
  if (!(dest = malloc(sizeof(char) * (n + 1))))
    return NULL;
  while (iterator < n)
    {
      dest[iterator] = src[iterator];
      iterator += 1;
    }
  dest[iterator] = '\0';
  return (dest);
}
