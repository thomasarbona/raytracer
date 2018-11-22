/*
** sphere.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 16:16:08 2017 Thomas ARBONA
** Last update Mon Mar 13 14:31:13 2017 Thomas ARBONA
*/
#ifndef OBJ_SPHERE_H_
# define OBJ_SPHERE_H_

# include "vector.h"

typedef struct	s_sphere
{
  float		radius;
}		t_sphere;

void	*sphere_create();
void	sphere_update();
void	sphere_intersect();
void	sphere_getnormal();

#endif /* !OBJ_SPHERE_H_ */
