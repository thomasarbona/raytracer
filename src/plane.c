/*
** plane.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Mar 17 11:43:26 2017 Thomas ARBONA
** Last update Fri Mar 17 15:28:53 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  return (-eye_pos.z / dir_vector.z <= 0 || dir_vector.z == 0
	  ? -1. : -eye_pos.z / dir_vector.z);
}

sfVector3f	get_normal_plane(int upward)
{
  if (upward)
    return ((sfVector3f){0, 0, 1});
  else
    return ((sfVector3f){0, 0, -1});
}
