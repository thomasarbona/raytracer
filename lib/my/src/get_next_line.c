/*
** get_next_line.c for get_next_line in /home/arbona/tek1/CPE/CPE_2016_getnextline
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan  3 15:03:01 2017 Thomas ARBONA
** Last update Tue Mar  7 10:46:27 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"

void    str_nconcat(char **s1, char *s2, int n)
{
  char	*out;
  int	len;
  int	index;

  index = 0;
  len = my_strlen(*s1);
  if (s2[0] == 0 ||
      !(out = malloc(sizeof(char) * (len + n + 1))))
    return;
  while (index < len + n)
    {
      out[index] = (index < len)
	? (*s1)[index]
	: s2[index - len];
      index += 1;
    }
  out[index] = 0;
  free(*s1);
  (*s1) = out;
}

int	get_endofline_pos(char *str, int n)
{
  int	index;

  index = 0;
  while (index < n)
    {
      if (str[index] == '\n')
	return (index);
      index += 1;
    }
  return (-1);
}

int	handle_endofline(char *buff, char **out, int *index, int n)
{
  int	eol_pos;

  if (*index != -1 && (eol_pos = get_endofline_pos(buff, n)) != -1)
    {
      str_nconcat(out, buff, eol_pos);
      (*index) += eol_pos + 1;
      return (1);
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	index = 0;
  static int	rbytes = 0;
  char		*out;

  out = NULL;
  if (index == -1)
    return (NULL);
  if (handle_endofline(buff + index, &out, &index, rbytes - index))
    return (out);
  str_nconcat(&out, buff + index, rbytes - index);
  while ((rbytes = read(fd, &buff, READ_SIZE)) > 0)
    {
      buff[rbytes] = 0;
      index = 0;
      if (handle_endofline(buff, &out, &index, rbytes))
	return (out);
      str_nconcat(&out, buff, rbytes);
    }
  if (my_strlen(buff + index) && rbytes)
    str_nconcat(&out, buff + index, my_strlen(buff + index));
  rbytes = 0;
  index = -1;
  return (out);
}
