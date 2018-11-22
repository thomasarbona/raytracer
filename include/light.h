/*
** light.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 22:37:42 2017 Thomas ARBONA
** Last update Mon Mar 13 15:41:30 2017 Thomas ARBONA
*/
#ifndef LIGHT_H_
# define LIGHT_H_

# include <SFML/Graphics/Color.h>
# include "matrix.h"

typedef struct	s_light
{
  t_matrix44	matrix;
  float		power;
  sfColor	color;
}		t_light;

t_light		*light_create();

#endif /* !LIGHT_H_ */
