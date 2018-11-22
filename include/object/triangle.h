/*
** triangle.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 02:17:52 2017 Thomas ARBONA
** Last update Thu Mar 16 02:24:34 2017 Thomas ARBONA
*/
#ifndef TRIANGLE_H_
# define TRIANGLE_H_

# include "matrix.h"

typedef struct	s_triangle
{
  t_matrix41	v1;
  t_matrix41	v2;
  t_matrix41	v3;
}		t_triangle;

void	*triangle_create();
void	triangle_intersect();
void	triangle_update();
void	triangle_getnormal();

#endif /* !TRIANGLE_H_ */
