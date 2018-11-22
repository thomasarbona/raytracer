/*
** my_str_replace.c for my in /home/arbona/CPool/CPool_bistro-matic/lib/my/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Nov  5 16:24:25 2016 Thomas Arbona
** Last update Sat Nov  5 19:02:52 2016 Thomas Arbona
*/
#include <stdlib.h>

int	my_strlen(char *);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);

char	*my_str_replace(char *str, int x, int y, char *replace)
{
  char	*result;
  int	result_len;
  int	index;

  index = 0;
  result_len = my_strlen(str) - (y - x) + my_strlen(replace);
  if (!(result = malloc(sizeof(char) * result_len)))
    return (NULL);
  my_strncpy(result, str, x);
  my_strcpy(result + x, replace);
  my_strcpy(result + x + my_strlen(replace), str + y + 1);
  return (result);
}
