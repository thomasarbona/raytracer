/*
** plane.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar  8 17:17:53 2017 Thomas ARBONA
** Last update Sun Mar 19 22:29:31 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "scene.h"
#include "scene/ray.h"
#include "object.h"
#include "object/plane.h"

void		*plane_create(int args[OBJ_MAX_ARGS])
{
  t_plane	*plane;

  (void)args;
  if (!(plane = malloc(sizeof(t_plane))))
    return (NULL);
  return ((void*)plane);
}

void	plane_intersect(t_scene *scene, t_ray *ray,
			t_obj *obj, t_hit *hit)
{
  (void)scene;
  (void)obj;
  hit->dist = -ray->pos[1] / ray->dir[1] <= 0
    ? -1.
    : -ray->pos[1] / ray->dir[1];
  object_gethitpoint(ray, hit);
}

void	plane_update(void *obj, char **data)
{
  (void)obj;
  (void)data;
}

void		plane_getnormal(t_ray *ray, t_impact *impact)
{
  (void)impact;
  ray_init(ray);
  ray->dir[X] = 0;
  ray->dir[Y] = 1;
  ray->dir[Z] = 0;
}
