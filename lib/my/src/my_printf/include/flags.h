/*
** flags.h for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/include
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 13:14:14 2016 Thomas ARBONA
** Last update Thu Nov 17 09:55:04 2016 Thomas ARBONA
*/
#ifndef FLAGS_H_
# define FLAGS_H_

# include "fmt.h"

# define ALTFLAG        (1 << 0)
# define ZEROFLAG       (1 << 1)
# define LEFTFLAG       (1 << 2)
# define BLANKFLAG      (1 << 3)
# define SIGNFLAG       (1 << 4)
# define HALFHALFFLAG   (1 << 5)
# define HALFFLAG       (1 << 6)
# define LONGFLAG       (1 << 7)
# define LONGLONGFLAG   (1 << 8)
# define INTMAXFLAG	(1 << 9)
# define PTRDIFFFLAG	(1 << 10)
# define SIZETFLAG	(1 << 11)
# define SIGNEDFLAG	(1 << 12)

void	set_altform_flag(char, t_specs_data *);
void	set_padding_flag(char, t_specs_data *);
void	set_sign_flag(char, t_specs_data *);
void	set_half_modif(char, t_specs_data *);
void	set_long_modif(char, t_specs_data *);
void	set_typed_modif(char, t_specs_data *);
char	*lli_to_str(t_specs_data *, t_pfargs *);
char	*lli_to_octstr(t_specs_data *, t_pfargs *);
char	*lli_to_hexastr(t_specs_data *, t_pfargs *);
char	*lli_to_binstr(t_specs_data *, t_pfargs *);
char	*ptr_to_str(t_specs_data *, t_pfargs *);
char	*char_to_str(t_specs_data *, t_pfargs *);
char	*str_to_str(t_specs_data *, t_pfargs *);
char	*percent_to_str(t_specs_data *, t_pfargs *);
char	*lli_to_basestr(t_ulli, char *);

#endif /* FLAGS_H_ */
