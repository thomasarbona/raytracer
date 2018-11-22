/*
** fmt.h for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Mon Nov 14 19:34:24 2016 Thomas ARBONA
** Last update Wed Nov 23 18:09:49 2016 Thomas ARBONA
*/
#ifndef FMT_H_
# define FMT_H_

typedef unsigned long long int	t_ulli;

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include "parser.h"
# include "spec.h"
# include "pfargs.h"
# include "flags.h"

typedef struct	s_fmt_data
{
  char		*buff;
  int		buff_cur;
  int		cursor;
  int		index;
  int		on_specs;
}		t_fmt_data;

# define BUFF_SIZE	1024

# define BASE_BINARY	"01"
# define BASE_OCTAL	"01234567"
# define BASE_HEXA	"0123456789abcdef"
# define BASE_HEXA_X	"0123456789ABCDEF"

int     my_strlen(char *);
void    my_memset(char *, int, char);
char	*my_strdup(char *);
char    *my_strndup(char *, int);
int     my_getnbr(char *);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_getnbr(char *);
int	my_str_contain(char *, char);
int	my_ull_intlen(unsigned long long int);
int	my_power_rec(int, int);
void	my_memset(char *, int, char);
char	*my_str_concat(char *, char *);
char	*my_str_replace(char *, int, int, char *);

char	*eval_fmt(const char *, va_list);
t_ulli	get_nbarg(t_specs_data *, t_pfargs *);
char	*set_width(t_specs_data *, char *);

int	my_sprintf(char *, const char *, ...);
int	my_snprintf(char *, int, const char *, ...);
int	my_dprintf(int, const char *, ...);

int	my_vsprintf(char *, const char *, va_list);
int	my_vsnprintf(char *, int, const char *, va_list);
int	my_vdprintf(int, const char *, va_list);

#endif /* !FMT_H_ */
