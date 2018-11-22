/*
** cylinder.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 12:06:30 2017 Thomas ARBONA
** Last update Fri Mar 17 10:55:42 2017 Thomas ARBONA
*/
#ifndef CYLINDER_H_
# define CYLINDER_H_

typedef struct	s_cylinder
{
  float		radius;
  float		height;
}		t_cylinder;

void	*cylinder_create();
void	cylinder_intersect();
void	cylinder_update();
void	cylinder_getnormal();

#endif /* !CYLINDER_H_ */
