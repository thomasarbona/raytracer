/*
** intersect_sphere.c for raytracer in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Feb 24 10:12:33 2017 Thomas ARBONA
<<<<<<< HEAD
** Last update Thu Mar 23 11:34:07 2017 Thomas ARBONA
=======
** Last update Mon Mar 20 13:54:00 2017 Thomas Arbona
>>>>>>> eb08a38081658833a102a2f4d70909a27702e679
*/
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>
#include <math.h>
#include "my.h"

sfVector3f	normalize_vect(sfVector3f);

float           intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector,
			       float semiangle)
{
  sfVector3f    eq;
  sfVector2f    sol;
  float         delta;
  float		ta;

  if (semiangle == 90)
    return (-1.);
  ta = pow(tanf(semiangle * M_PI / 180.), 2);
  eq.x = ((dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y)
	  / ta) - (dir_vector.z * dir_vector.z);
  eq.y = 2. * ((dir_vector.x * eye_pos.x + eye_pos.y * dir_vector.y)
	       / ta) - (2.0 * dir_vector.z * eye_pos.z);
  eq.z = ((eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y) / ta)
    - (eye_pos.z * eye_pos.z);
  delta = eq.y * eq.y - 4 * eq.x * eq.z;
  if (delta < 0)
    return (-1.);
  if (delta == 0)
    return (-eq.y / (2 * eq.x));
  sol.x = (-eq.y + sqrt(delta)) / (2 * eq.x);
  sol.y = (delta > 0) ? (-eq.y - sqrt(delta)) / (2 * eq.x) : -1.;
  return (sol.x < 0 && sol.y < 0 ? -1. :
	  sol.x > sol.y ? sol.y < 0 ? sol.x : sol.y
	  : sol.x < 0 ? sol.y : sol.x);
}

sfVector3f	get_normal_cone(sfVector3f inter, float semiangle)
{
  sfVector3f	normal;

  normal.x = inter.x;
  normal.y = inter.y;
  normal.z = -tanf(semiangle * M_PI / 180.) * inter.z;
  return (normalize_vect(normal));
}
