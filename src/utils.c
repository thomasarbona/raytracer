/*
** utils.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Mar 17 11:51:17 2017 Thomas ARBONA
** Last update Fri Mar 17 11:59:42 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>
#include <math.h>

sfVector3f	normalize_vect(sfVector3f vect)
{
  float		norm;

  norm = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
  if (norm == 0.)
    return (vect);
  vect.x /= norm;
  vect.y /= norm;
  vect.z /= norm;
  return (vect);
}
