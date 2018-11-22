/*
** my_strncat.c for my_strncat in /home/arbona/CPool/CPool_Day07
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Tue Oct 11 10:07:54 2016 Thomas Arbona
** Last update Tue Oct 11 10:23:45 2016 Thomas Arbona
*/

int	my_strlen(char *str);

char	*my_strncat(char *dest, char *src, int nb)
{
  int	dest_len;
  int	iterator;

  iterator = 0;
  dest_len = my_strlen(dest);
  while (src[iterator] != '\0' && iterator < nb)
    {
      dest[dest_len + iterator] = src[iterator];
      iterator += 1;
    }
  dest[dest_len + iterator] = '\0';
  return (dest);
}
