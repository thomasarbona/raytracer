/*
** my_str_islower.c for my_str_islower in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:54:42 2016 Thomas Arbona
** Last update Mon Oct 10 19:20:11 2016 Thomas Arbona
*/

int	my_str_islower(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (!('a' <= str[iterator] && str[iterator] <= 'z'))
	return (0);
      iterator += 1;
    }
  return (1);
}
