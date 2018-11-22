/*
** my_str_isprintable.c for my_str_isprintable in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:54:42 2016 Thomas Arbona
** Last update Mon Oct 10 19:32:26 2016 Thomas Arbona
*/

int	my_str_isprintable(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (0 <= str[iterator] && str[iterator] <= 31)
	return (0);
      iterator += 1;
    }
  return (1);
}
