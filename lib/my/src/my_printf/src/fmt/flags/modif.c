/*
** modif.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src/fmt/flags
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 13:46:54 2016 Thomas ARBONA
** Last update Fri Mar  3 13:29:59 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

void	set_long_modif(char token, t_specs_data *sdata)
{
  if (token == 'l')
    {
      if (sdata->flags & LONGFLAG)
	sdata->flags |= LONGLONGFLAG;
      sdata->flags |= LONGFLAG;
    }
  else if (token == 'L')
    sdata->flags |= LONGLONGFLAG;
}

void	set_half_modif(char token, t_specs_data *sdata)
{
  (void)token;
  if (sdata->flags & HALFFLAG)
    sdata->flags |= HALFHALFFLAG;
  sdata->flags |= HALFFLAG;
}

void	set_typed_modif(char token, t_specs_data *sdata)
{
  if (token == 'j')
    sdata->flags |= INTMAXFLAG;
  else if (token == 't')
    sdata->flags |= PTRDIFFFLAG;
  else if (token == 'z')
    sdata->flags |= SIZETFLAG;
}
