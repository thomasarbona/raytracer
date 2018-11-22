/*
** rotation.c for raytracer in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 14 20:06:00 2017 Thomas ARBONA
** Last update Tue Feb 14 20:22:32 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>
#include <math.h>
#include "util.h"

static void	rotate_x(sfVector3f *to_rotate, float angle)
{
  sfVector3f	tmp;

  tmp.y = to_rotate->y * cos(angle) + to_rotate->z * -sin(angle);
  tmp.z = to_rotate->y * sin(angle) + to_rotate->z * cos(angle);
  to_rotate->y = tmp.y;
  to_rotate->z = tmp.z;
}

static void	rotate_y(sfVector3f *to_rotate, float angle)
{
  sfVector3f	tmp;

  tmp.x = to_rotate->x * cos(angle) + to_rotate->z * sin(angle);
  tmp.z = to_rotate->x * -sin(angle) + to_rotate->z * cos(angle);
  to_rotate->x = tmp.x;
  to_rotate->z = tmp.z;
}

static void	rotate_z(sfVector3f *to_rotate, float angle)
{
  sfVector3f	tmp;

  tmp.x = to_rotate->x * cos(angle) + to_rotate->y * -sin(angle);
  tmp.y = to_rotate->x * sin(angle) + to_rotate->y * cos(angle);
  to_rotate->x = tmp.x;
  to_rotate->y = tmp.y;
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  angles.x *= DEG2RADCONV;
  angles.y *= DEG2RADCONV;
  angles.z *= DEG2RADCONV;
  rotate_x(&to_rotate, angles.x);
  rotate_y(&to_rotate, angles.y);
  rotate_z(&to_rotate, angles.z);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  angles.x *= DEG2RADCONV;
  angles.y *= DEG2RADCONV;
  angles.z *= DEG2RADCONV;
  rotate_z(&to_rotate, angles.z);
  rotate_y(&to_rotate, angles.y);
  rotate_x(&to_rotate, angles.x);
  return (to_rotate);
}
