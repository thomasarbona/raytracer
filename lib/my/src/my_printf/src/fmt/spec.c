/*
** spec.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 10:05:06 2016 Thomas ARBONA
** Last update Fri Mar  3 13:30:46 2017 Thomas ARBONA
*/
#include "../../include/fmt.h"

t_spec_flag	g_specs_flags[] = {
  {'#', TYPE_FLAG, &set_altform_flag},
  {'0', TYPE_FLAG, &set_padding_flag},
  {'-', TYPE_FLAG, &set_padding_flag},
  {' ', TYPE_FLAG, &set_sign_flag},
  {'+', TYPE_FLAG, &set_sign_flag},
  //{'\'', TYPE_FLAG, NULL},
  //{'I', TYPE_FLAG, NULL},
  {'h', TYPE_MODIF, &set_half_modif},
  {'l', TYPE_MODIF, &set_long_modif},
  {'L', TYPE_MODIF, &set_long_modif},
  {'j', TYPE_MODIF, &set_typed_modif},
  {'t', TYPE_MODIF, &set_typed_modif},
  {'z', TYPE_MODIF, &set_typed_modif},
  {'\0', 0, NULL}
};

t_spec_conv	g_specs_convs[] = {
  {'d', TYPE_CONV, &lli_to_str},
  {'i', TYPE_CONV, &lli_to_str},
  {'o', TYPE_CONV, &lli_to_octstr},
  {'u', TYPE_CONV, &lli_to_str},
  {'x', TYPE_CONV, &lli_to_hexastr},
  {'X', TYPE_CONV, &lli_to_hexastr},
  {'c', TYPE_CONV, &char_to_str},
  {'s', TYPE_CONV, &str_to_str},
  {'S', TYPE_CONV, &str_to_str},
  {'p', TYPE_CONV, &ptr_to_str},
  {'b', TYPE_CONV, &lli_to_binstr},
  //{'n', TYPE_CONV, NULL},
  //{'m', TYPE_CONV, NULL},
  {'%', TYPE_CONV, &percent_to_str},
  {'\0', 0, NULL}
};

char	*percent_to_str(t_specs_data *sdata, t_pfargs *pfargs)
{
  (void)sdata;
  (void)pfargs;
  return ("%");
}

t_spec_conv	*get_spec_conv(char token)
{
  int		index;

  index = 0;
  while (g_specs_convs[index].token != token &&
	 g_specs_convs[index].token != '\0')
    index += 1;
  return (&g_specs_convs[index]);
}

t_spec_flag	*get_spec_flag(char token)
{
  int		index;

  index = 0;
  while (g_specs_flags[index].token != token &&
	 g_specs_flags[index].token != '\0')
    index += 1;
  return (&g_specs_flags[index]);
}

char		*eval_specs(char *specs, t_pfargs *pfargs)
{
  t_specs_data	sdata;
  char		*specs_cpy;
  t_spec_conv	*conv_spec;
  char		*out;
  char		*fmt_out;

  specs_cpy = my_strdup(specs);
  specs += 1;
  sdata.flags = 0;
  parse_arg_idx(&specs, &sdata);
  parse_flags(&specs, &sdata);
  parse_width(&specs, &sdata, pfargs);
  parse_prec(&specs, &sdata, pfargs);
  parse_modif(&specs, &sdata);
  if (!((conv_spec = get_spec_conv(specs[0]))->type & TYPE_CONV))
    return (specs_cpy);
  sdata.conv = specs[0];
  out = conv_spec->func(&sdata, pfargs);
  free(specs_cpy);
  fmt_out = set_width(&sdata, out);
  return (fmt_out);
}
