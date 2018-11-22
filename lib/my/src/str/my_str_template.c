/*
** my_str_template.c for  in /home/arbona/Projects/libs/lib/my/src/str/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Nov  9 12:55:24 2016 Thomas Arbona
** Last update Wed Nov  9 14:42:09 2016 Thomas Arbona
*/
#include <stdarg.h>

#define FLAG	"%s"

int	my_strlen(char *);
char	*my_str_replace(char *, int, int, char *);

static int	is_valid_flag(char *template, int index)
{
  return (!(index + 1 <= my_strlen(template) &&
	   !(template[index] == FLAG[0] &&
	     template[index + 1] == FLAG[1]) ||
	   index - 1 >= 0 && template[index - 1] == FLAG[0]));
}

char		*my_str_template(char *template, ...)
{
  int		index;
  char		*value;
  va_list	ap;

  index = 0;
  va_start(ap, template);
  while (template[index] != '\0')
    {
      if (is_valid_flag(template, index))
	{
	  value = va_arg(ap, char*);
	  template = my_str_replace(template, index, index + 1, value);
	}
      index += 1;
    }
  va_end(ap);
  return (template);
}
