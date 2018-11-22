/*
** my_memset.c for my in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 19:45:19 2016 Thomas ARBONA
** Last update Mon Nov 14 19:46:23 2016 Thomas ARBONA
*/

void	my_memset(char *str, int n, char c)
{
  int	index;

  index = 0;
  while (index < n)
    {
      str[index] = c;
      index += 1;
    }
  str[n - 1] = '\0';
}
