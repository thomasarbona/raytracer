/*
** material.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Mar 19 17:32:33 2017 Thomas ARBONA
** Last update Sun Mar 19 22:28:45 2017 Thomas ARBONA
*/
#include <math.h>
#include "object.h"
#include "scene.h"

static sfColor	cget_inv(sfColor color)
{
  sfColor	out;

  out.r = 255 - color.r;
  out.g = 255 - color.g;
  out.b = 255 - color.b;
  out.a = 255;
  return (out);
}

sfColor		material_getcolor(t_obj *obj, t_matrix41 pos)
{
  float		n;
  sfColor	color;
  sfColor	min;
  sfColor	max;

  n = get_perlin(pos[X] * obj->perlin, pos[Y] * obj->perlin,
	       pos[Z] * obj->perlin);
  min = obj->color;
  max = cget_inv(obj->color);
  if (obj->material == MAT_WOOD)
    {
      n = 20 * n;
      n -= floorf(n);
      min = WOOD_C2;
      max = WOOD_C3;
    }
  color.r = min.r * n + max.r * (1 - n);
  color.g = min.g * n + max.g * (1 - n);
  color.b = min.b * n + max.b * (1 - n);
  return (color);
}
