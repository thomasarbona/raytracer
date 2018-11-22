/*
** my_str_islower.c for my_str_islower in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:54:42 2016 Thomas Arbona
** Last update Mon Oct 10 19:24:02 2016 Thomas Arbona
*/

int	my_str_isupper(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (!('A' <= str[iterator] && str[iterator] <= 'Z'))
	return (0);
      iterator += 1;
    }
  return (1);
}
