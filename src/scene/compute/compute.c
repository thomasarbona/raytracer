/*
** compute.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar  1 11:13:59 2017 Thomas ARBONA
** Last update Sun Mar 19 22:29:57 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "scene.h"
#include "object.h"
#include "scene/frame/put_pixel.h"

float		scene_intersect(t_scene *scene,
				t_ray *ray,
				t_impact *impact,
				float k)
{
  t_obj		*obj;
  t_hit		hit;
  int		index;
  t_ray		tmp;

  index = 0;
  if (impact == NULL && !(impact = malloc(sizeof(t_impact))))
    return (-1.);
  impact->hit.dist = -1.;
  while (index < vector_getsize(&scene->objects))
    {
      obj = vector_get(&scene->objects, index, t_obj);
      matrix44_multiply41(tmp.pos, obj->matrix_inv, ray->pos);
      matrix44_multiply41(tmp.dir, obj->matrix_inv, ray->dir);
      obj->intersect(scene, &tmp, obj, &hit);
      if (hit.dist > k &&
	  (impact->hit.dist == -1. || hit.dist < impact->hit.dist))
	{
	  impact->hit = hit;
	  impact->obj = obj;
	}
      index += 1;
    }
  return (impact->hit.dist);
}

static void	scene_initray(t_scene *scene, t_ray *ray, sfVector2i *cursor)
{
  t_ray		tmp;

  ray_init(&tmp);
  ray_getdir(&tmp, scene, cursor);
  matrix44_multiply41(ray->pos, scene->camera, tmp.pos);
  matrix44_multiply41(ray->dir, scene->camera, tmp.dir);
}

void		scene_compute(t_scene *scene)
{
  sfVector2i	cursor;
  t_ray		ray;
  t_impact	impact;

  cursor.y = 0;
  framebuffer_clear(&scene->frame, 0);
  while (cursor.y < scene->frame.height)
    {
      cursor.x = 0;
      while (cursor.x < scene->frame.width)
	{
	  scene_initray(scene, &ray, &cursor);
	  impact.ray = ray;
	  scene_intersect(scene, &ray, &impact, 0.);
	  if (impact.hit.dist != -1)
	    {
	      scene_computelight(scene, &impact, 0);
	      put_pixel(&scene->frame, cursor.x, cursor.y, impact.color);
	    }
	  cursor.x += 1;
	}
      cursor.y += 1;
    }
}
