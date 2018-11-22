/*
** sphere.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 16:01:01 2017 Thomas ARBONA
** Last update Sun Mar 19 22:16:29 2017 Thomas ARBONA
*/
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "scene.h"
#include "scene/ray.h"
#include "object.h"
#include "object/sphere.h"
#include "my.h"

void		*sphere_create(int args[OBJ_MAX_ARGS])
{
  t_sphere	*sphere;

  if (!(sphere = malloc(sizeof(t_sphere))))
    return (NULL);
  sphere->radius = args[0];
  return ((void*)sphere);
}

static void	sphere_intersect2(sfVector2f *sol, sfVector3f *eq,
				  float delta, t_hit *hit)
{
  sol->x = (-eq->y + sqrt(delta)) / (2 * eq->x);
  sol->y = (delta > 0) ? (-eq->y - sqrt(delta)) / (2 * eq->x) : -1.;
  hit->dist = (sol->x < 0 && sol->y < 0 ? -1. :
	       sol->x > sol->y
	       ? sol->y < 0 ? sol->x : sol->y
	       : sol->x < 0 ? sol->y : sol->x);
}

void		sphere_intersect(t_scene *scene, t_ray *ray,
				 t_obj *obj, t_hit *hit)
{
  sfVector3f    eq;
  sfVector2f    sol;
  float         delta;
  float		radius;

  (void)scene;
  radius = ((t_sphere*)obj->data)->radius;
  eq.x = ray->dir[0] * ray->dir[0] +
    ray->dir[1] * ray->dir[1] +
    ray->dir[2] * ray->dir[2];
  eq.y = 2. * (ray->pos[0] * ray->dir[0] +
	       ray->pos[1] * ray->dir[1] +
	       ray->pos[2] * ray->dir[2]);
  eq.z = ray->pos[0] * ray->pos[0] + ray->pos[1] * ray->pos[1] +
    ray->pos[2] * ray->pos[2] - radius * radius;
  delta = eq.y * eq.y - 4 * eq.x * eq.z;
  if (delta < 0.0)
    hit->dist = -1.;
  else if (delta == 0.0)
    hit->dist = -eq.y / (2. * eq.x);
  else
    sphere_intersect2(&sol, &eq, delta, hit);
  object_gethitpoint(ray, hit);
}

void		sphere_update(void *obj, char **data)
{
  t_sphere	*sphere;

  sphere = (t_sphere*)obj;
  sphere->radius = my_atof(data[0]);
}

void		sphere_getnormal(t_ray *ray, t_impact *impact)
{
  ray_init(ray);
  //matrix44_multiply41(pos, impact->obj->matrix, impact->hit.pos);
  ray->pos[X] = impact->hit.pos[X];
  ray->pos[Y] = impact->hit.pos[Y];
  ray->pos[Z] = impact->hit.pos[Z];
  ray->dir[X] = impact->hit.pos[X];
  ray->dir[Y] = impact->hit.pos[Y];
  ray->dir[Z] = impact->hit.pos[Z];
  //matrix44_multiply41(ray->pos, impact->obj->matrix, tmp.pos);
  //matrix44_multiply41(ray->dir, impact->obj->matrix, tmp.dir);
  ray_normalize(ray);
}
