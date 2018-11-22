/*
** object.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 15:18:54 2017 Thomas ARBONA
** Last update Sun Mar 19 22:17:33 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "object.h"
#include "vector.h"
#include "my.h"

t_objfunc	g_objfunc[] = {
  {"sphere", 1,
   sphere_create, sphere_intersect,
   sphere_update, sphere_getnormal},
  {"plane", 0,
   plane_create, plane_intersect,
   plane_update, plane_getnormal},
  {"cylinder", 1,
   cylinder_create, cylinder_intersect,
   cylinder_update, cylinder_getnormal},
  {"cone", 1,
   cone_create, cone_intersect,
   cone_update, cone_getnormal},
  {0, 0, 0, 0, 0, 0}
};

static t_objfunc	*object_getfunc(char *token)
{
  int			index;

  index = 0;
  while (g_objfunc[index].token != 0)
    {
      if (my_strcmp(g_objfunc[index].token, token) == 0)
	break;
      index += 1;
    }
  return (g_objfunc[index].token != 0 ? &g_objfunc[index] : NULL);
}

static void	object_init(t_obj *obj, t_objfunc *objfunc,
			    int args[OBJ_MAX_ARGS])
{
  obj->color = sfWhite;
  obj->reflection = 0.;
  obj->data = objfunc->create(args);
  obj->intersect = objfunc->intersect;
  obj->update = objfunc->update;
  obj->getnormal = objfunc->getnormal;
  obj->material = 0;
  obj->perlin = 1.;
}

t_obj		*object_create(char *token, ...)
{
  va_list	ap;
  t_obj		*obj;
  t_objfunc	*objfunc;
  int		args[OBJ_MAX_ARGS];
  int		index;

  va_start(ap, token);
  if ((objfunc = object_getfunc(token)) == NULL ||
      !(obj = malloc(sizeof(t_obj))))
    return (NULL);
  index = 0;
  while (index < objfunc->nb_args)
    {
      args[index] = va_arg(ap, int);
      index += 1;
    }
  matrix44_init(obj->matrix);
  object_init(obj, objfunc, args);
  va_end(ap);
  return (obj);
}
