/*
** fmt.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src/fmt
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 16:12:38 2016 Thomas ARBONA
** Last update Sun Mar 19 21:17:16 2017 Thomas ARBONA
*/
#include "../../include/fmt.h"

static void	init_fmt_data(t_fmt_data *fmt_data)
{

  if (!(fmt_data->buff = malloc(sizeof(char) * BUFF_SIZE)))
    return;
  my_memset(fmt_data->buff, BUFF_SIZE, '0');
  fmt_data->buff_cur = 0;
  fmt_data->cursor = 0;
  fmt_data->index = 0;
  fmt_data->on_specs = 0;
}

static char	*push_buffer(t_fmt_data *fmt_data, char *str)
{
  char		*tmp_buff;
  int		buff_len;

  while (fmt_data->buff_cur + my_strlen(str) >= my_strlen(fmt_data->buff))
    {
      buff_len = my_strlen(fmt_data->buff) + BUFF_SIZE;
      if (!(tmp_buff = malloc(sizeof(char) * buff_len)))
	return (NULL);
      my_strcpy(tmp_buff, fmt_data->buff);
      my_memset(tmp_buff + my_strlen(fmt_data->buff),
		buff_len - my_strlen(fmt_data->buff), '0');
      fmt_data->buff = my_strdup(tmp_buff);
      free(tmp_buff);
    }
  my_strcpy(fmt_data->buff + fmt_data->buff_cur, str);
  fmt_data->buff[fmt_data->buff_cur + my_strlen(str)] = '0';
  fmt_data->buff_cur += my_strlen(str);
  return (fmt_data->buff);
}

static void	handle_specs(const char *fmt,
			     t_fmt_data *fdata,
			     t_pfargs *pfargs)
{
  char		*tmp_str;
  char		*fmt_spec;
  int		tmp_len;

  tmp_len = fdata->index - fdata->cursor + 1;
  if ((fmt[fdata->index] == '%' && !fdata->on_specs) ||
      fmt[fdata->index] == '\0')
    {
      tmp_str = my_strndup((char*)fmt + fdata->cursor, tmp_len - 1);
      push_buffer(fdata, tmp_str);
      fdata->cursor = fdata->index;
      fdata->on_specs = 1;
      free(tmp_str);
    }
  else if ((get_spec_conv(fmt[fdata->index])->type &
	    TYPE_CONV) && fdata->on_specs)
    {
      tmp_str = my_strndup((char*)fmt + fdata->cursor, tmp_len);
      fmt_spec = eval_specs(tmp_str, pfargs);
      push_buffer(fdata, fmt_spec);
      fdata->cursor = fdata->index + 1;
      fdata->on_specs = 0;
      free(tmp_str);
      free(fmt_spec);
    }
}

char		*eval_fmt(const char *fmt, va_list ap)
{
  t_fmt_data	fdata;
  t_pfargs	pfargs;
  char		*out;

  if (fmt == NULL)
    return ("");
  init_pfargs(&pfargs, ap);
  init_fmt_data(&fdata);
  while (fmt[fdata.index] != '\0')
    {
      handle_specs(fmt, &fdata, &pfargs);
      fdata.index += 1;
    }
  handle_specs(fmt, &fdata, &pfargs);
  fdata.buff[fdata.buff_cur] = '\0';
  out = my_strdup(fdata.buff);
  free(fdata.buff);
  return (out);
}
