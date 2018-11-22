/*
** setter.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar  8 16:05:14 2017 Thomas ARBONA
** Last update Sun Mar 19 22:27:35 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>
#include "object.h"
#include "matrix.h"
#include "my.h"

void		parser_objsetpos(t_obj *obj, char **data)
{
  sfVector3f	trans;

  trans.x = data[0] ? my_atof(data[0]) : 0.;
  trans.y = data[0] && data[1] ? my_atof(data[1]) : 0.;
  trans.z = data[0] && data[1] && data[2] ? my_atof(data[2]) : 0.;
  matrix44_translate(obj->matrix, &trans);
}

void		parser_objsetcolor(t_obj *obj, char **data)
{
  sfColor	color;
  int		f;

  f = 0;
  if (my_strcmp("wood", data[0]) == 0)
    {
      obj->material = MAT_WOOD;
      return;
    }
  if (my_strcmp("perlin", data[0]) == 0)
    {
      obj->material = MAT_PERLIN;
      obj->perlin = my_atof(data[1]);
      f = 2;
    }
  color.r = data[0 + f] ? my_getnbr(data[0 + f]) : 0;
  color.g = data[0 + f] && data[1 + f] ? my_getnbr(data[1 + f]) : 0;
  color.b = data[0 + f] && data[1 + f] && data[2 + f]
    ? my_getnbr(data[2 + f]) : 0;
  color.a = 255;
  obj->color = color;
}

void	parser_objsetparameter(t_obj *obj, char **data)
{
  obj->update(obj->data, data);
}

void		parser_objsetrotation(t_obj *obj, char **data)
{
  sfVector3f	rot;

  rot.x = data[0] ? my_atof(data[0]) : 0.;
  rot.y = data[0] && data[1] ? my_atof(data[1]) : 0.;
  rot.z = data[0] && data[1] && data[2] ? my_atof(data[2]) : 0.;
  matrix44_rotate(obj->matrix, &rot);
}

void	parser_objsetreflection(t_obj *obj, char **data)
{
  obj->reflection = my_atof(data[0]);
}
