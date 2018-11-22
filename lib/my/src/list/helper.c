/*
** helper.c for my in /home/arbona/libs/_my
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Feb  1 14:10:33 2017 Thomas ARBONA
** Last update Fri Feb 24 16:24:09 2017 Thomas ARBONA
*/
#include <unistd.h>
#include "../../include/my.h"

int		list_indexof(t_list **list, t_list *node)
{
  t_list	*curr;
  int		index;

  index = 0;
  if (*list == NULL)
    return (-1);
  curr = *list;
  while (curr != NULL)
    {
      if (node == curr)
	return (index);
      index += 1;
      curr = curr->next;
    }
  return (-1);
}

int		list_len(t_list **list)
{
  t_list	*curr;
  int		len;

  len = 0;
  if (*list == NULL)
    return (len);
  curr = *list;
  while (curr != NULL)
    {
      len += 1;
      curr = curr->next;
    }
  return (len);
}
