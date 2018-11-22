/*
** str_to_str.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 02:13:58 2016 Thomas ARBONA
** Last update Fri Mar  3 13:29:29 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

static char	*fmt_nprint_char(char *str, t_specs_data *sdata)
{
  int		index;
  char		*tmp_str;
  char		*npc;

  index = 0;
  while (sdata->conv == 'S' && str[index] != '\0')
    {
      if (str[index] < 32 || 127 <= str[index])
	{
	  npc = lli_to_basestr((long long)str[index], BASE_OCTAL);
	  tmp_str = (my_strlen(npc) == 1) ? "\\00" :
	    (my_strlen(npc) == 2) ? "\\0" :
	    "\\";
	  tmp_str = my_str_concat(tmp_str, npc);
	  str = my_str_replace(str, index, index, tmp_str);
	}
      index += 1;
    }
  return (str);
}

char	*str_to_str(t_specs_data *sdata, t_pfargs *pfargs)
{
  char	*str;
  int	index;

  index = 0;
  if (sdata->arg_idx > 0)
    goto_pfargs(pfargs, sdata->arg_idx);
  str = (sdata->arg_idx > 0)
    ? va_arg(pfargs->ap_cpy, char *)
    : va_arg(pfargs->ap, char *);
  if (str == NULL)
    return ((sdata->prec != -1 && sdata->prec < 6) ? "" : "(null)");
  str = my_strdup(str);
  if (sdata->conv == 'S')
    str = fmt_nprint_char(str, sdata);
  if (sdata->prec != -1 && sdata->prec < my_strlen(str))
    str[sdata->prec] = '\0';
  return (str);
}
