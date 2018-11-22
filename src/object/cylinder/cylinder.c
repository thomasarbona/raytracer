/*
** cylinder.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 16:01:01 2017 Thomas ARBONA
** Last update Sun Mar 19 22:10:38 2017 Thomas ARBONA
*/
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "scene.h"
#include "scene/ray.h"
#include "object.h"
#include "object/cylinder.h"
#include "my.h"

void		*cylinder_create(int args[OBJ_MAX_ARGS])
{
  t_cylinder	*cylinder;

  if (!(cylinder = malloc(sizeof(t_cylinder))))
    return (NULL);
  cylinder->radius = args[0];
  cylinder->height = -1;
  return ((void*)cylinder);
}

static void	cylinder_intersect2(sfVector2f *sol, sfVector3f *eq,
				    float delta, t_hit *hit)
{
  sol->x = (-eq->y + sqrt(delta)) / (2 * eq->x);
  sol->y = (delta > 0) ? (-eq->y - sqrt(delta)) / (2 * eq->x) : -1.;
  hit->dist = (sol->x < 0 && sol->y < 0 ? -1. :
	       sol->x > sol->y
	       ? sol->y < 0 ? sol->x : sol->y
	       : sol->x < 0 ? sol->y : sol->x);
}

void		cylinder_intersect(t_scene *scene, t_ray *ray,
				   t_obj *obj, t_hit *hit)
{
  sfVector3f    eq;
  sfVector2f    sol;
  float         delta;
  t_cylinder    *cyl;

  (void)scene;
  cyl = ((t_cylinder*)obj->data);
  eq.x = ray->dir[0] * ray->dir[0] +
    ray->dir[2] * ray->dir[2];
  eq.y = 2. * (ray->pos[0] * ray->dir[0] +
	       ray->pos[2] * ray->dir[2]);
  eq.z = ray->pos[0] * ray->pos[0] +
    ray->pos[2] * ray->pos[2] - cyl->radius * cyl->radius;
  delta = eq.y * eq.y - 4 * eq.x * eq.z;
  if (delta < 0.0)
    hit->dist = -1.;
  else if (delta == 0.0)
    hit->dist = -eq.y / (2. * eq.x);
  else
    cylinder_intersect2(&sol, &eq, delta, hit);
  object_gethitpoint(ray, hit);
  if (cyl->height != -1. && (hit->pos[Y] < 0. || hit->pos[Y] > cyl->height))
    hit->dist = -1.;
}

void		cylinder_update(void *obj, char **data)
{
  t_cylinder	*cylinder;

  cylinder = (t_cylinder*)obj;
  cylinder->radius = my_atof(data[0]);
  if (data[1] != NULL)
    cylinder->height = my_atof(data[1]);
}

void		cylinder_getnormal(t_ray *ray, t_impact *impact)
{
  ray_init(ray);
  //matrix44_multiply41(pos, impact->obj->matrix, impact->hit.pos);
  ray->pos[X] = impact->hit.pos[X];
  ray->pos[Y] = impact->hit.pos[Y];
  ray->pos[Z] = impact->hit.pos[Z];
  ray->dir[X] = impact->hit.pos[X];
  ray->dir[Y] = 0;
  ray->dir[Z] = impact->hit.pos[Z];
  //matrix44_multiply41(ray->pos, impact->obj->matrix, tmp.pos);
  //matrix44_multiply41(ray->dir, impact->obj->matrix, tmp.dir);
  ray_normalize(ray);
}
