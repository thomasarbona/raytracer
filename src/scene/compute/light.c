/*
** light.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 10:00:05 2017 Thomas ARBONA
** Last update Sun Mar 19 21:59:15 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <math.h>
#include "scene.h"
#include "scene/vec.h"

static void	compute_light(t_impact *impact, t_light *light, float coef)
{
  sfColor	color;
  float		r;
  float		g;
  float		b;

  coef = (coef < 0.) ? 0. : (coef > 1.) ? 1. : coef;
  if (impact->obj->material)
    color = material_getcolor(impact->obj, impact->hit.pos);
  else
    color = impact->obj->color;
  coef *= light->power;
  r = ((float)color.r / 255. * (float)light->color.r / 255.) * coef * 255;
  g = ((float)color.g / 255. * (float)light->color.g / 255.) * coef * 255;
  b = ((float)color.b / 255. * (float)light->color.b / 255.) * coef * 255;
  impact->color.r = (impact->color.r + r > 255) ? 255 : impact->color.r + r;
  impact->color.g = (impact->color.g + g > 255) ? 255 : impact->color.g + g;
  impact->color.b = (impact->color.b + b > 255) ? 255 : impact->color.b + b;
}

static void	compute_raylight(t_ray *raylight, t_light *light,
				 t_impact *impact, t_matrix41 pos)
{
  t_ray		tmplight;

  ray_init(&tmplight);
  ray_init(raylight);
  matrix44_multiply41(raylight->pos, light->matrix, tmplight.pos);
  matrix44_multiply41(pos, impact->obj->matrix, impact->hit.pos);
  raylight->dir[X] = raylight->pos[X] - pos[X];
  raylight->dir[Y] = raylight->pos[Y] - pos[Y];
  raylight->dir[Z] = raylight->pos[Z] - pos[Z];
  ray_normalize(raylight);

}

static void	compute_rayobj(t_ray *ray, t_ray *raylight, t_matrix41 pos)
{
  ray_init(ray);
  ray->pos[X] = pos[X];
  ray->pos[Y] = pos[Y];
  ray->pos[Z] = pos[Z];
  ray->dir[X] = raylight->pos[X] - ray->pos[X];
  ray->dir[Y] = raylight->pos[Y] - ray->pos[Y];
  ray->dir[Z] = raylight->pos[Z] - ray->pos[Z];
  ray_normalize(ray);
}

static void	compute_normal(t_ray *ray2, t_impact *impact)
{
  t_ray		tray2;

  impact->obj->getnormal(&tray2, impact);
  matrix44_multiply41(ray2->pos, impact->obj->matrix, tray2.pos);
  matrix44_multiply41(ray2->dir, impact->obj->matrix, tray2.dir);
}

void		scene_computelight(t_scene *scene,
				   t_impact *impact,
				   int call)
{
  t_light	*light;
  t_ray		ray2;
  t_ray		ray3;
  t_ray		raylight;
  t_matrix41	pos;
  float		coef;
  float		dist;
  t_impact	impact2;
  int		index;

  index = -1;
  impact->color = (sfColor){0, 0, 0, 255};
  while (++index != vector_getsize(&scene->lights) && (coef = 1.))
    {
      light = vector_get(&scene->lights, index, t_light);
        compute_normal(&ray2, impact);
      compute_raylight(&raylight, light, impact, pos);
      coef = ray_getscalar(&raylight, &ray2);
      compute_rayobj(&ray3, &raylight, pos);
      if ((dist = scene_intersect(scene, &ray3, &impact2, scene->kepsilon)) >
	  0.0 && dist < vector_getdist(raylight.pos, ray3.pos))
	coef = 0.0;
      compute_light(impact, light, coef);
      scene_computereflection(scene, impact, &ray2, call);
    }
}
