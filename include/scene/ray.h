/*
** ray.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  2 16:42:30 2017 Thomas ARBONA
** Last update Wed Mar 15 18:22:39 2017 Thomas ARBONA
*/
#ifndef RAY_H_
# define RAY_H_

# include <SFML/System/Vector2.h>
# include "matrix.h"

typedef struct	s_ray
{
  t_matrix41	pos;
  t_matrix41	dir;
}		t_ray;

typedef struct  s_scene t_scene;

void	ray_init(t_ray*);
void	ray_normalize(t_ray*);
void	ray_getdir(t_ray*, t_scene*, sfVector2i*);
float	ray_getscalar(t_ray*, t_ray*);

#endif /* !RAY_H_ */
