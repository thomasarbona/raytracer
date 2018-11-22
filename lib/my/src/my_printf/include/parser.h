/*
** parser.h for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Tue Nov 15 19:53:56 2016 Thomas ARBONA
** Last update Wed Nov 16 18:20:37 2016 Thomas ARBONA
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "pfargs.h"
# include "spec.h"

int	parse_arg_idx(char **, t_specs_data *);
int	parse_flags(char **, t_specs_data *);
int	parse_width(char **, t_specs_data *, t_pfargs *);
int	parse_prec(char **, t_specs_data *, t_pfargs *);
int	parse_modif(char **, t_specs_data *);

#endif /* !PARSER_H_ */
