/*
** copy.c for matrix in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar 14 00:06:01 2017 Thomas ARBONA
** Last update Thu Mar 16 16:05:28 2017 Thomas ARBONA
*/
#include "matrix.h"

void	matrix44_copy(t_matrix44 dest, t_matrix44 src)
{
  dest[0][0] = src[0][0];
  dest[0][1] = src[0][1];
  dest[0][2] = src[0][2];
  dest[0][3] = src[0][3];
  dest[1][0] = src[1][0];
  dest[1][1] = src[1][1];
  dest[1][2] = src[1][2];
  dest[1][3] = src[1][3];
  dest[2][0] = src[2][0];
  dest[2][1] = src[2][1];
  dest[2][2] = src[2][2];
  dest[2][3] = src[2][3];
  dest[3][0] = src[3][0];
  dest[3][1] = src[3][1];
  dest[3][2] = src[3][2];
  dest[3][3] = src[3][3];
}

void	matrix41_copy(t_matrix41 dest, t_matrix41 src)
{
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
  dest[3] = src[3];
}
