/*
** my_str_concat.c for my in /home/arbona/Projects/libs/lib/my/src/str/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  8 10:18:35 2016 Thomas Arbona
** Last update Wed Nov  9 11:10:54 2016 Thomas Arbona
*/
#include <stdlib.h>

int	my_strlen(char *);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);

char	*my_str_concat(char *a, char *b)
{
  char	*result;

  if (!(result = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1))))
    return (NULL);
  my_strcpy(result, a);
  my_strcat(result, b);
  return (result);
}
