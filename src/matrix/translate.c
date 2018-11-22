/*
** translate.c for matrix in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Feb 22 15:31:20 2017 Thomas ARBONA
** Last update Tue Mar 14 13:44:01 2017 Thomas ARBONA
*/
#include "matrix.h"

void		matrix44_translate(t_matrix44 matrix, sfVector3f *translate)
{
  t_matrix44	tmatrix;
  t_matrix44	result;

  matrix44_init(tmatrix);
  tmatrix[0][3] = translate->x;
  tmatrix[1][3] = translate->y;
  tmatrix[2][3] = translate->z;
  matrix44_multiply44(result, matrix, tmatrix);
  matrix44_copy(matrix, result);
}
