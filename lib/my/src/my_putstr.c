/*
** my_putstr.c for my_putstr in /home/arbona/CPool/CPool_Day04
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct  6 08:45:27 2016 Thomas Arbona
** Last update Mon Nov  7 10:34:36 2016 Thomas Arbona
*/
#include <unistd.h>

int	my_strlen(char *);

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
