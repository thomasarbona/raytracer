/*
** calc_dir_vector.c for raytracer in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 14 19:50:12 2017 Thomas ARBONA
** Last update Tue Feb 14 19:57:18 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir;

  dir.x = dist_to_plane;
  dir.y = (screen_size.x / 2.) - screen_pos.x;
  dir.z = (screen_size.y / 2.) - screen_pos.y;
  return (dir);
}
