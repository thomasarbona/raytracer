/*
** hit.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 10:52:25 2017 Thomas ARBONA
** Last update Wed Mar 15 18:33:44 2017 Thomas ARBONA
*/
#include "scene.h"
#include "matrix.h"

void	object_gethitpoint(t_ray *ray, t_hit *hit)
{
  hit->pos[X] = ray->pos[X] + ray->dir[X] * hit->dist;
  hit->pos[Y] = ray->pos[Y] + ray->dir[Y] * hit->dist;
  hit->pos[Z] = ray->pos[Z] + ray->dir[Z] * hit->dist;
  hit->pos[W] = 1;
}
