/*
** remove.c for my in /home/arbona/libs/_my
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 27 19:35:12 2017 Thomas ARBONA
** Last update Fri Feb 24 16:23:43 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "../../include/my.h"

t_list		*list_remove(t_list **list, t_list *node)
{
  t_list        *curr;
  t_list        *tmp;

  if (*list == node)
    {
      tmp = *list;
      *list = (*list)->next;
      return (*list);
    }
  curr = *list;
  while (curr != node && curr != NULL)
    curr = curr->next;
  if (curr == node)
    {
      tmp = curr;
      curr->prev->next = curr->next;
      if (curr->next != NULL)
	curr->next->prev = curr->prev;
      return (tmp);
    }
  return (curr);
}

t_list		*list_shift(t_list **list)
{
  t_list	*tmp;

  if (*list == NULL)
    return (NULL);
  tmp = *list;
  *list = (*list)->next;
  return (tmp);
}

t_list		*list_pop(t_list **list)
{
  t_list	*tmp;

  if (*list == NULL)
    return (NULL);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  list_remove(list, tmp);
  return (tmp);
}
