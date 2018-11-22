/*
** cylinder.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar 16 12:06:30 2017 Thomas ARBONA
** Last update Fri Mar 17 11:21:45 2017 Thomas ARBONA
*/
#ifndef CONE_H_
# define CONE_H_

typedef struct	s_cone
{
  float		alpha;
  float		height;
}		t_cone;

void	*cone_create();
void	cone_intersect();
void	cone_update();
void	cone_getnormal();

#endif /* !CONE_H_ */
