/*
** cylinder.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 16:01:01 2017 Thomas ARBONA
** Last update Sun Mar 19 21:22:30 2017 Thomas ARBONA
*/
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "scene.h"
#include "scene/ray.h"
#include "object.h"
#include "object/cone.h"
#include "my.h"

void		*cone_create(int args[OBJ_MAX_ARGS])
{
  t_cone	*cone;

  if (!(cone = malloc(sizeof(t_cone))))
    return (NULL);
  cone->alpha = args[0];
  cone->height = -1;
  return ((void*)cone);
}

static void	cone_intersect2(sfVector2f *sol, sfVector3f eq,
				float delta, t_hit *hit)
{
  sol->x = (-eq.y + sqrt(delta)) / (2 * eq.x);
  sol->y = (delta > 0) ? (-eq.y - sqrt(delta)) / (2 * eq.x) : -1.;
  hit->dist = (sol->x < 0 && sol->y < 0 ? -1. :
	       sol->x > sol->y
	       ? sol->y < 0 ? sol->x : sol->y
	       : sol->x < 0 ? sol->y : sol->x);
}

void		cone_intersect(t_scene *scene, t_ray *ray,
			       t_obj *obj, t_hit *hit)
{
  sfVector3f    eq;
  sfVector2f    sol;
  float         delta;
  t_cone	*cone;
  float		tanalpha;

  (void)scene;
  cone = ((t_cone*)obj->data);
  tanalpha = tanf(cone->alpha) * tanf(cone->alpha);
  eq.x = ((ray->dir[X] * ray->dir[X] + ray->dir[Z] * ray->dir[Z]) / tanalpha)
    - (ray->dir[Y] * ray->dir[Y]);
  eq.y = 2. * ((ray->dir[X] * ray->pos[X] + ray->pos[Z] *
		ray->dir[Z]) / tanalpha) - (2.0 * ray->dir[Y] * ray->pos[Y]);
  eq.z = ((ray->pos[X] * ray->pos[X] + ray->pos[Z] * ray->pos[Z]) / tanalpha)
    - (ray->pos[Y] * ray->pos[Y]);
  delta = eq.y * eq.y - 4 * eq.x * eq.z;
  if (delta < 0.0)
    hit->dist = -1.;
  else if (delta == 0.0)
    hit->dist = -eq.y / (2. * eq.x);
  else
    cone_intersect2(&sol, eq, delta, hit);
  object_gethitpoint(ray, hit);
  if (cone->height != -1. && (hit->pos[Y] > 0. || hit->pos[Y] < -cone->height))
    hit->dist = -1.;
}

void		cone_update(void *obj, char **data)
{
  t_cone	*cone;

  cone = (t_cone*)obj;
  cone->alpha = my_atof(data[0]) * M_PI / 180.;
  if (data[1] != NULL)
    cone->height = my_atof(data[1]);
}

void		cone_getnormal(t_ray *ray, t_impact *impact)
{
  t_cone	*cone;

  cone = (t_cone*)impact->obj->data;
  ray_init(ray);
  ray->pos[X] = impact->hit.pos[X];
  ray->pos[Y] = impact->hit.pos[Y];
  ray->pos[Z] = impact->hit.pos[Z];
  ray->dir[X] = impact->hit.pos[X];
  ray->dir[Y] = -tanf(cone->alpha) * impact->hit.pos[Y];
  ray->dir[Z] = impact->hit.pos[Z];
  ray_normalize(ray);
}
