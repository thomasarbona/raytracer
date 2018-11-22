/*
** my_strlen.c for my_strlen in /home/arbona/CPool/CPool_Day04
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct  6 08:51:35 2016 Thomas Arbona
** Last update Thu Feb 16 11:19:50 2017 Thomas ARBONA
*/
#include "unistd.h"

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  if (str == NULL)
    return (0);
  while (str[count] != '\0')
    count += 1;
  return (count);
}
