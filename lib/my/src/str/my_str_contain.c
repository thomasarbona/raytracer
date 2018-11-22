/*
** my_sort_int_tab.c for my in /home/CPool/libs/my
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct  6 17:50:13 2016 Thomas Arbona
** Last update Mon Nov  7 10:36:44 2016 Thomas Arbona
*/

int	my_str_contain(char *str, char to_find)
{
  int	index;

  index = 0;
  while (str[index])
    {
      if (str[index] == to_find)
	return (index);
      index += 1;
    }
  return (-1);
}
