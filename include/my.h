/*
** my.h for libmy in /home/arbona/CPool/CPool_Day09
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct 13 09:22:28 2016 Thomas Arbona
** Last update Mon Mar 13 14:17:28 2017 Thomas ARBONA
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>

char	*convert_base(char *, char *, char *);
int	my_find_prime_sup(int);
int	my_getnbr_base(char *, char *);
int	my_getnbr(char *);
double	my_atof(char*);
int	my_is_prime(int);
int	my_power_rec(int, int);
void	my_putchar(char);
int	my_putnbr_base(int, char *);
int	my_put_nbr(int);
int	my_putstr(char *);
char	*my_revstr(char *);
int	my_showmem(char *, int);
int	my_showstr(char *);
int	my_show_wordtab(char **);
void	my_sort_int_tab(int *, int);
int	my_square_root(int);
char	*my_strcapitalize(char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
int	my_str_isalpha(char *);
int	my_str_islower(char *);
int	my_str_isnum(char *);
int	my_str_isprintable(char *);
int	my_str_isupper(char *);
int	my_strlen(char *);
char	*my_strlowcase(char *);
char	*my_strncat(char *, char *, int);
int	my_strncmp(char *, char *, int);
char	*my_strncpy(char *, char *, int);
char	*my_strstr(char *, char *);
char	**my_str_to_wordtab(char *, char *);
char	*my_strupcase(char *);
int	my_swap(int *, int *);
int	my_swapchar(char **, int, int);
int	my_swapstr(char **, char **);
int	my_find_in_wordtab(char **, char *);
void	my_memset(char *, int, char);
int	my_str_contain(char *, char);
int	my_tablen(void **);
char	*my_str_replace(char *, int, int, char *);
int	my_intlen(int);
int	my_l_intlen(long int);
int	my_ll_intlen(long long int);
int	my_u_intlen(unsigned int);
int	my_ul_intlen(unsigned long int);
int	my_ull_intlen(unsigned long long int);
char	*my_int_str(int);
char	*my_l_int_str(long int);
char	*my_ll_int_str(long long int);
char	*my_u_int_str(unsigned int);
char	*my_ul_int_str(unsigned long int);
char	*my_ull_int_str(unsigned long long int);
char	*my_str_concat(char *, char *);
char	*my_str_template(char *template, ...);

int	my_printf(const char *, ...);
int	my_sprintf(char *, const char *, ...);
int	my_snprintf(char *, int, const char *, ...);
int	my_dprintf(int, const char *, ...);
char	*my_asprintf(const char*, ...);

int	my_vprintf(const char *, va_list);
int	my_vsprintf(char *, const char *, va_list);
int	my_vsnprintf(char *, int, const char *, va_list);
int	my_vdprintf(int, const char *, va_list);
char	*my_vasprintf(const char *, va_list);

typedef struct  s_list
{
  void          *element;
  struct s_list *prev;
  struct s_list *next;
}               t_list;

t_list  *list_push(t_list**, void*);
t_list  *list_insert(t_list**, int, void*);
t_list  *list_unshift(t_list**, void*);

t_list  *list_remove(t_list**, t_list*);
t_list  *list_shift(t_list**);
t_list  *list_pop(t_list**);

void    _list_foreach(t_list**, void (*func)(t_list*));

int     list_indexof(t_list**, t_list*);
int     list_len(t_list**);

# define list_foreach(l, c, b)  (_list_foreach(l, ({void f(t_list *c)b f;})))

# ifndef GET_NEXT_LINE_H_
#  define GET_NEXT_LINE_H_

#  ifndef READ_SIZE
#   define READ_SIZE     2048
#  endif /* !READ_SIZE */

char    *get_next_line(const int);

# endif /* !GET_NEXT_LINE_H_ */

#endif /* !MY_H_ */
