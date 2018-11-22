/*
** inverse.c for matrix in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Feb 23 17:51:49 2017 Thomas ARBONA
** Last update Mon Mar  6 11:33:00 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "matrix.h"

void		matrix44_submat(t_matrix33 msub, t_matrix44 matrix, int x, int y)
{
  sfVector2i	dest;
  sfVector2i	t;

  t.y = 0;
  while (t.y != 4)
    {
      dest.y = t.y;
      if (t.y > y)
	dest.y -= 1;
      t.x = 0;
      while (t.x != 4)
	{
	  dest.x = t.x;
	  if (t.x > x)
	    dest.x -= 1;
	  if (t.x != x && t.y != y)
	    msub[dest.y][dest.x] = matrix[t.y][t.x];
	  t.x += 1;
	}
      t.y += 1;
    }
}

float		matrix33_getdet(t_matrix33 m)
{
  return (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
	  - m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2])
	  + m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));
}

float		matrix44_getdet(t_matrix44 matrix)
{
  float		det;
  float		result;
  float		index;
  t_matrix33	msub;
  int		n;

  result = 0.;
  index = 1;
  n = 0;
  while (n != 4)
    {
      matrix44_submat(msub, matrix, 0, n);
      det = matrix33_getdet(msub);
      result += matrix[n][0] * det * index;
      n += 1;
      index *= -1;
    }
  return (result);
}

void		matrix44_inverse(t_matrix44 minv, t_matrix44 matrix)
{
  t_matrix33	mtemp;
  sfVector2i	index;
  float		mdet;
  int		sign;

  index.y = 0;
  mdet = matrix44_getdet(matrix);
  while (index.y != 4)
    {
      index.x = 0;
      while (index.x != 4)
	{
	  sign = 1 - ((index.x + index.y) % 2) * 2;
	  matrix44_submat(mtemp, matrix, index.x, index.y);
	  minv[index.x][index.y] =
	    (matrix33_getdet(mtemp) * (float)sign) / mdet;
	  index.x += 1;
	}
      index.y += 1;
    }
}
