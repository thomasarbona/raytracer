/*
** cross.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 01:49:28 2017 Thomas ARBONA
** Last update Thu Mar 16 18:30:36 2017 Thomas ARBONA
*/
#include "matrix.h"

void	matrix41_cross(t_matrix41 result, t_matrix41 m1, t_matrix41 m2)
{
  result[0] = -(m1[Y] * m2[Z] - m1[Z] * m2[Y]);
  result[1] = -(m1[Z] * m2[X] - m1[X] * m2[Z]);
  result[2] = -(m1[X] * m2[Y] - m1[Y] * m2[X]);
  result[3] = 0;
}
