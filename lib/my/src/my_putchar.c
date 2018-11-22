/*
** my_putchar.c for my_putchar in /home/arbona/CPool/CPool_Day07/lib/my
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Tue Oct 11 09:28:35 2016 Thomas Arbona
** Last update Tue Oct 11 10:31:38 2016 Thomas Arbona
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
