/*
** my_strcpy.c for my_strcpy in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 08:13:34 2016 Thomas Arbona
** Last update Wed Oct 12 10:55:24 2016 Thomas Arbona
*/

char	*my_strcpy(char *dest, char *src)
{
  int	iterator;

  iterator = 0;
  while (src[iterator] != '\0')
    {
      dest[iterator] = src[iterator];
      iterator += 1;
    }
  dest[iterator] = '\0';
  return (dest);
}
