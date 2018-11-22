/*
** light.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Mar 17 11:41:07 2017 Thomas ARBONA
** Last update Fri Mar 17 12:00:25 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>

sfVector3f	normalize_vect(sfVector3f);

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	coef;

  light_vector = normalize_vect(light_vector);
  normal_vector = normalize_vect(normal_vector);
  coef = light_vector.x * normal_vector.x +
    light_vector.y * normal_vector.y +
    light_vector.z * normal_vector.z;
  if (coef > 1.)
    coef = 1.;
  if (coef < 0.)
    coef = 0.;
  return (coef);
}
