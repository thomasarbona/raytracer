/*
** foreach.c for my in /home/arbona/libs/_my
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 27 19:37:28 2017 Thomas ARBONA
** Last update Fri Feb 24 16:24:36 2017 Thomas ARBONA
*/
#include <unistd.h>
#include "../../include/my.h"

void		_list_foreach(t_list **list, void (*func)(t_list *))
{
  t_list	*curr;

  curr = *list;
  while (curr != NULL)
    {
      func(curr);
      curr = curr->next;
    }
}
