/*
** add.c for my in /home/arbona/libs/_my
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 27 19:23:20 2017 Thomas ARBONA
** Last update Fri Feb 24 16:23:10 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "../../include/my.h"

static t_list	*node_create(void *element)
{
  t_list	*node;

  if (!(node = malloc(sizeof(t_list))))
    return (NULL);
  node->prev = NULL;
  node->next = NULL;
  node->element = element;
  return (node);
}

t_list		*list_insert(t_list **list, int index, void *element)
{
  t_list	*curr;
  t_list	*new;
  int		cursor;

  new = node_create(element);
  curr = *list;
  cursor = 0;
  while (curr->next != NULL && cursor != index)
    curr = curr->next;
  if (curr->next != NULL)
    new->next = curr->next;
  new->prev = curr;
  curr->next = new;
  return (new);
}

t_list		*list_push(t_list **list, void *element)
{
  t_list	*curr;
  t_list	*new;

  new = node_create(element);
  if (*list == NULL)
    return (*list = new);
  curr = *list;
  while (curr->next != NULL)
    curr = curr->next;
  new->prev = curr;
  curr->next = new;
  return (new);
}

t_list		*list_unshift(t_list **list, void *element)
{
  t_list	*curr;
  t_list	*new;

  new = node_create(element);
  if (*list == NULL)
    return (*list = element);
  new->next = *list;
  (*list)->prev = new;
  *list = new;
  return (new);
}
