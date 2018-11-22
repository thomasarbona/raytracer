/*
** width.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 11:24:17 2016 Thomas ARBONA
** Last update Fri Mar  3 13:30:56 2017 Thomas ARBONA
*/
#include "../../include/fmt.h"

static char	*format_width(t_specs_data *sdata,
				  char *out,
				  char wchar,
				  char *padding)
{
  if ((sdata->conv == 'i' || sdata->conv == 'd') &&
      (out[0] == '-' || out[0] == '+') && sdata->flags & ZEROFLAG)
    {
      wchar = out[0];
      out[0] = '0';
      out = my_str_concat(padding, out);
      out[0] = wchar;
      return (out);
    }
  if ((sdata->conv == 'x' || sdata->conv == 'X') &&
      (sdata->flags & ALTFLAG) && (sdata->flags & ZEROFLAG))
    {
      wchar = out[1];
      out[1] = '0';
      out = my_str_concat(padding, out);
      out[1] = wchar;
      return (out);
    }
  return ((sdata->flags & LEFTFLAG)
	  ? my_str_concat(out, padding)
	  : my_str_concat(padding, out));
}

char		*set_width(t_specs_data *sdata, char *str)
{
  char		wchar;
  int           len;
  char          *padding;
  char		*out;

  if (sdata->width <= my_strlen(str) || sdata->conv == '%')
    return (my_strdup(str));
  wchar = (sdata->flags & ZEROFLAG && sdata->prec < 0 &&
	   my_str_contain("dibouxX", sdata->conv) >= 0) ? '0' : ' ';
  len = sdata->width - my_strlen(str) + 1;
  if (!(padding = malloc(sizeof(char) * len)))
    return (NULL);
  my_memset(padding, len, wchar);
  out = format_width(sdata, str, wchar, padding);
  free(padding);
  return (out);
}
