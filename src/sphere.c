/*
** intersect_sphere.c for raytracer in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Feb 24 10:12:33 2017 Thomas ARBONA
** Last update Fri Mar 17 14:49:16 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>
#include <math.h>
#include "my.h"

sfVector3f	normalize_vect(sfVector3f);

float           intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector,
				 float radius)
{
  sfVector3f    eq;
  sfVector2f    sol;
  float         delta;

  eq.x = dir_vector.x * dir_vector.x +
        dir_vector.y * dir_vector.y +
    dir_vector.z * dir_vector.z;
  eq.y = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y +
	      eye_pos.z * dir_vector.z);
  eq.z = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y +
    eye_pos.z * eye_pos.z - radius * radius;
  delta = eq.y * eq.y - 4 * eq.x * eq.z;
  if (delta < 0)
    return (-1.);
  if (delta == 0)
    return (-eq.y / (2 * eq.x));
  sol.x = (-eq.y + sqrt(delta)) / (2 * eq.x);
  sol.y = (delta > 0) ? (-eq.y - sqrt(delta)) / (2 * eq.x) : -1.;
  if (sol.x < 0 && sol.y < 0)
    return (-1.);
  return (sol.x > sol.y
	  ? sol.y < 0 ? sol.x : sol.y
	  : sol.x < 0 ? sol.y : sol.x);
}

sfVector3f	get_normal_sphere(sfVector3f inter)
{
  sfVector3f	normal;

  normal.x = inter.x;
  normal.y = inter.y;
  normal.z = inter.z;
  return (normalize_vect(normal));
}
