/*
** flag.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 14:17:06 2016 Thomas ARBONA
** Last update Fri Mar  3 13:29:46 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

void	set_altform_flag(char token, t_specs_data *sdata)
{
  (void)token;
  sdata->flags |= ALTFLAG;
}

void	set_padding_flag(char token, t_specs_data *sdata)
{
  if (token == '0')
    {
      if (!(sdata->flags & LEFTFLAG))
	sdata->flags |= ZEROFLAG;
    }
  else if (token == '-')
    {
      if (sdata->flags & ZEROFLAG)
	sdata->flags ^= ZEROFLAG;
      sdata->flags |= LEFTFLAG;
    }
}

void	set_sign_flag(char token, t_specs_data *sdata)
{
  if (token == ' ')
    {
      if (!(sdata->flags & SIGNFLAG))
	sdata->flags |= BLANKFLAG;
    }
  else if (token == '+')
    {
      if (sdata->flags & BLANKFLAG)
	sdata->flags ^= BLANKFLAG;
      sdata->flags |= SIGNFLAG;
    }
}
