/*
** my_str_to_wordtab2.c for libmy in /home/arbona/CPool/libmy/lib/my
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct 13 19:33:21 2016 Thomas Arbona
** Last update Mon Nov  7 10:37:53 2016 Thomas Arbona
*/

#include <stdlib.h>

char	*my_strndup(char *src, int n);
char	*my_strstr(char *, char*);

typedef struct	s_cursors
{
  int		one;
  int		two;
}		t_cursors;

typedef struct	s_array_cursor
{
  int		cursor;
  char		**array;
}		t_array_cursor;

static t_array_cursor	*array_push(t_array_cursor *arr, char *str)
{
  arr->cursor += 1;
  arr->array[arr->cursor] = str;
  return (arr);
}

static int	count_word(char *str,
			   int count,
			   t_cursors *cursors,
			   char *separators)
{
  if (str[cursors->two] == '\0')
    {
      if (cursors->one != cursors->two)
	count += 1;
      return (count);
    }
  if (my_strstr(separators, my_strndup(str + cursors->two, 1)))
    {
      cursors->one += 1;
      cursors->two += 1;
      if (cursors->one == cursors->two)
	return (count_word(str, count, cursors, separators));
      cursors->one = cursors->two;
      return (count_word(str, count + 1, cursors, separators));
    }
  cursors->two += 1;
  return (count_word(str, count, cursors, separators));
}

static char	**str_to_tab(char *str,
			     t_array_cursor *arr,
			     t_cursors *cursors,
			     char *separators)
{
  if (str[cursors->two] == '\0')
    {
      if (cursors->one != cursors->two)
	array_push(arr, my_strndup(str + cursors->one, cursors->two -
				   cursors->one));
      array_push(arr, NULL);
      return (arr->array);
    }
  if (my_strstr(separators, my_strndup(str + cursors->two, 1)))
    {
      if (cursors->one == cursors->two)
	{
	  cursors->one += 1;
	  cursors->two += 1;
	  return (str_to_tab(str, arr, cursors, separators));
	}
      array_push(arr, my_strndup(str + cursors->one, cursors->two -
				 cursors->one));
      cursors->two += 1;
      cursors->one = cursors->two;
      return (str_to_tab(str, arr, cursors, separators));
    }
  cursors->two += 1;
  return (str_to_tab(str, arr, cursors, separators));
}

char			**my_str_to_wordtab(char *str, char *separators)
{
  t_array_cursor	arr;
  int			count;
  t_cursors		cursors;

  cursors.one = 0;
  cursors.two = 0;
  count = count_word(str, 0, &cursors, separators);
  if (!(arr.array = malloc(sizeof(char *) * (count + 1))))
    return (NULL);
  arr.cursor = -1;
  cursors.one = 0;
  cursors.two = 0;
  return (str_to_tab(str, &arr, &cursors, separators));
}
