/*
** number.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf/src/fmt
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Wed Nov 16 14:31:10 2016 Thomas ARBONA
** Last update Fri Mar  3 13:27:51 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

t_ulli	get_ulli_arg(int flags, va_list ap)
{
  return ((flags & LONGLONGFLAG) ? va_arg(ap, unsigned long long) :
	  (flags & LONGFLAG) ? va_arg(ap, unsigned long) :
	  (flags & HALFHALFFLAG) ? (unsigned char)va_arg(ap, unsigned int) :
	  (flags & HALFFLAG) ? (unsigned short)va_arg(ap, unsigned int) :
	  (flags & INTMAXFLAG) ? va_arg(ap, uintmax_t) :
	  (flags & PTRDIFFFLAG) ? va_arg(ap, ptrdiff_t) :
	  (flags & SIZETFLAG) ? va_arg(ap, size_t) :
	  va_arg(ap, unsigned int));
}

t_ulli	get_lli_arg(int flags, va_list ap)
{
    return ((flags & LONGLONGFLAG) ? va_arg(ap, long long) :
    	  (flags & LONGFLAG) ? va_arg(ap, long) :
    	  (flags & HALFHALFFLAG) ? (signed char)va_arg(ap, int) :
    	  (flags & HALFFLAG) ? (short)va_arg(ap, int) :
    	  (flags & INTMAXFLAG) ? va_arg(ap, intmax_t) :
    	  (flags & PTRDIFFFLAG) ? va_arg(ap, ptrdiff_t) :
    	  (flags & SIZETFLAG) ? va_arg(ap, ssize_t) :
    	  va_arg(ap, int));
}

t_ulli	get_nbarg(t_specs_data *sdata, t_pfargs *pfargs)
{
  if (sdata->arg_idx > 0)
    goto_pfargs(pfargs, sdata->arg_idx);
  if (my_str_contain("bouxX", sdata->conv) >= 0)
    return (get_ulli_arg(sdata->flags, (sdata->arg_idx > 0)
			 ? pfargs->ap_cpy : pfargs->ap));
  sdata->flags |= SIGNEDFLAG;
  return (get_lli_arg(sdata->flags, (sdata->arg_idx > 0)
		      ? pfargs->ap_cpy : pfargs->ap));
}
