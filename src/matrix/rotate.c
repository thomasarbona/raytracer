/*
** rotate.c for matrix in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Mar 13 23:36:53 2017 Thomas ARBONA
** Last update Sun Mar 19 22:26:56 2017 Thomas ARBONA
*/
#include <math.h>
#include "matrix.h"

static void	matrix44_rotatex(t_matrix44 matrix, float alpha)
{
  t_matrix44	rmatrix;
  t_matrix44	result;

  matrix44_init(rmatrix);
  rmatrix[1][1] = cos(alpha);
  rmatrix[2][1] = sin(alpha);
  rmatrix[1][2] = -sin(alpha);
  rmatrix[2][2] = cos(alpha);
  matrix44_multiply44(result, matrix, rmatrix);
  matrix44_copy(matrix, result);
}

static void	matrix44_rotatey(t_matrix44 matrix, float alpha)
{
  t_matrix44	rmatrix;
  t_matrix44	result;

  matrix44_init(rmatrix);
  rmatrix[0][0] = cos(alpha);
  rmatrix[0][2] = sin(alpha);
  rmatrix[2][0] = -sin(alpha);
  rmatrix[2][2] = cos(alpha);
  matrix44_multiply44(result, matrix, rmatrix);
  matrix44_copy(matrix, result);
}

static void	matrix44_rotatez(t_matrix44 matrix, float alpha)
{
  t_matrix44	rmatrix;
  t_matrix44	result;

  matrix44_init(rmatrix);
  rmatrix[0][0] = cos(alpha);
  rmatrix[1][0] = sin(alpha);
  rmatrix[0][1] = -sin(alpha);
  rmatrix[1][1] = cos(alpha);
  matrix44_multiply44(result, matrix, rmatrix);
  matrix44_copy(matrix, result);
}

void	matrix44_rotate(t_matrix44 matrix, sfVector3f *rotation)
{
  matrix44_rotatex(matrix, rotation->x * M_PI / 180.);
  matrix44_rotatey(matrix, rotation->y * M_PI / 180.);
  matrix44_rotatez(matrix, rotation->z * M_PI / 180.);
}
