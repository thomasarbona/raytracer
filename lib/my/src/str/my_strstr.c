/*
** my_strstr.c for my_strstr in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 09:38:25 2016 Thomas Arbona
** Last update Tue Oct 11 09:05:51 2016 Thomas Arbona
*/

#include <unistd.h>

int	my_strlen(char *str);
int	my_strncmp(char *s1, char *s2, int n);

char	*my_strstr(char *str, char *to_find)
{
  int	iterator;
  int	find_length;

  iterator = 0;
  find_length = my_strlen(to_find);
  while (str[iterator] != '\0')
    {
      if (!my_strncmp(&str[iterator], to_find, find_length))
	return (&str[iterator]);
      iterator += 1;
    }
  return (NULL);
}
