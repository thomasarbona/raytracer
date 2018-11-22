/*
** my_strcat.c for my_strcat in /home/arbona/CPool/CPool_Day07
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Tue Oct 11 09:38:20 2016 Thomas Arbona
** Last update Tue Oct 11 10:05:04 2016 Thomas Arbona
*/

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
  int	dest_len;
  int	iterator;

  iterator = 0;
  dest_len = my_strlen(dest);
  while (src[iterator] != '\0')
    {
      dest[dest_len + iterator] = src[iterator];
      iterator += 1;
    }
  dest[dest_len + iterator] = '\0';
  return (dest);
}
