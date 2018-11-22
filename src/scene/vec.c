/*
** vec.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 02:04:08 2017 Thomas ARBONA
** Last update Sun Mar 19 21:55:17 2017 Thomas ARBONA
*/
#include <math.h>
#include "matrix.h"

void     vector_sub(t_matrix41 a, t_matrix41 b, t_matrix41 c)
{
  a[X] = b[X] - c[X];
  a[Y] = b[Y] - c[Y];
  a[Z] = b[Z] - c[Z];
  a[W] = 0;
}

float	vector_getscalar(t_matrix41 a, t_matrix41 b)
{
  return (a[X] * b[X] + a[Y] * b[Y] + a[Z] + b[Z]);
}

float	vector_length(t_matrix41 a)
{
  return (sqrt(a[X] * a[X] + a[Y] * a[Y] + a[Z] * a[Z]));
}

float	vector_getdist(t_matrix41 a, t_matrix41 b)
{
  return (sqrt((b[X] - a[X]) * (b[X] - a[X]) +
	       (b[Y] - a[Y]) * (b[Y] - a[Y]) +
	       (b[Z] - a[Z]) * (b[Z] - a[Z])));
}
