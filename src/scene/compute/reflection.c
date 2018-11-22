/*
** reflection.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar 15 15:03:12 2017 Thomas ARBONA
** Last update Sun Mar 19 22:30:10 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "scene.h"

# define REFLEC_REC_MAX 4

static void	add_light(sfColor *c1, sfColor *c2, float coef)
{
  c1->r = c1->r * (1 - coef) + c2->r * coef;
  c1->g = c1->g * (1 - coef) + c2->g * coef;
  c1->b = c1->b * (1 - coef) + c2->b * coef;
}

static void	scene_interreflec(t_scene *scene,
				  t_ray *ray,
				  t_impact *impact,
				  int call)
{
  t_obj         *obj;
  t_hit         hit;
  int           index;
  t_ray         tmp;

  index = -1;
  if (impact == NULL && !(impact = malloc(sizeof(t_impact))))
    return;
  impact->hit.dist = -1.;
  while (++index != vector_getsize(&scene->objects))
    {
      obj = vector_get(&scene->objects, index, t_obj);
      matrix44_multiply41(tmp.pos, obj->matrix_inv, ray->pos);
      matrix44_multiply41(tmp.dir, obj->matrix_inv, ray->dir);
      obj->intersect(scene, &tmp, obj, &hit);
      if (hit.dist > scene->kepsilon &&
	  (impact->hit.dist == -1. || hit.dist < impact->hit.dist))
	{
	  impact->hit = hit;
	  impact->obj = obj;
	}
    }
  if (impact->hit.dist != -1 && call < REFLEC_REC_MAX)
    scene_computelight(scene, impact, call + 1);
}

void		scene_computereflection(t_scene *scene,
					t_impact *impact,
					t_ray *normal,
					int call)
{
  t_impact	refimp;
  t_ray		ray;
  float		coef;
  t_matrix41	imppos;

  if (impact->obj->reflection == 0)
    return;
  ray_init(&ray);
  matrix44_multiply41(imppos, impact->obj->matrix, impact->hit.pos);
  ray.pos[X] = imppos[X];
  ray.pos[Y] = imppos[Y];
  ray.pos[Z] = imppos[Z];
  matrix44_multiply41(ray.dir, impact->obj->matrix, impact->ray.dir);
  coef = 2. * ray_getscalar(&ray, normal);
  ray.dir[X] -= coef * normal->dir[X];
  ray.dir[Y] -= coef * normal->dir[Y];
  ray.dir[Z] -= coef * normal->dir[Z];
  ray_normalize(&ray);
  refimp.ray = ray;
  scene_interreflec(scene, &ray, &refimp, call);
  if (refimp.hit.dist == -1.)
    refimp.color = sfBlack;
  add_light(&impact->color, &refimp.color, impact->obj->reflection);
}
