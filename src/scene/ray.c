/*
** ray.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  2 16:52:08 2017 Thomas ARBONA
** Last update Thu Mar 16 02:03:45 2017 Thomas ARBONA
*/
#include <math.h>
#include "scene/ray.h"
#include "scene.h"

void	ray_init(t_ray *ray)
{
  ray->pos[0] = 0.0;
  ray->pos[1] = 0.0;
  ray->pos[2] = 0.0;
  ray->pos[3] = 1.0;
  ray->dir[0] = 0.0;
  ray->dir[1] = 0.0;
  ray->dir[2] = 0.0;
  ray->dir[3] = 0.0;
}

void	ray_normalize(t_ray *ray)
{
  float	norm;

  norm = sqrt(ray->dir[0] * ray->dir[0] +
	      ray->dir[1] * ray->dir[1] +
	      ray->dir[2] * ray->dir[2] +
	      ray->dir[3] * ray->dir[3]);
  ray->dir[0] /= norm;
  ray->dir[1] /= norm;
  ray->dir[2] /= norm;
  ray->dir[3] /= norm;
}

void	ray_getdir(t_ray *ray, t_scene *scene, sfVector2i *cursor)
{
  ray->dir[0] = (float)cursor->x / (float)scene->frame.width;
  ray->dir[1] = ((float)scene->frame.height - (float)cursor->y)
    / (float)scene->frame.height;
  ray->dir[2] = -1.0;
  ray->dir[0] = ray->dir[0] * 2. - 1.;
  ray->dir[1] = ray->dir[1] * 2. - 1.;
  ray_normalize(ray);
}

float	ray_getscalar(t_ray *r1, t_ray *r2)
{
  return (r1->dir[X] * r2->dir[X] +
	  r1->dir[Y] * r2->dir[Y] +
	  r1->dir[Z] * r2->dir[Z]);
}
