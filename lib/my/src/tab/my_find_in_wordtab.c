/*
** my_find_in_tab.c for libmy in /home/arbona/CPool/libmy/lib/my
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Tue Oct 25 10:09:33 2016 Thomas Arbona
** Last update Tue Oct 25 16:07:23 2016 Thomas Arbona
*/

#include <stdlib.h>

int	my_strcmp(char *, char*);

int	my_find_in_wordtab(char **arr, char *search)
{
  int	cursor;

  cursor = 0;
  while (arr[cursor] != NULL)
    {
      if (my_strcmp(arr[cursor], search) == 0)
	return (cursor);
      cursor += 1;
    }
  return (-1);
}
