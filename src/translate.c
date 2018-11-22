/*
** translate.c for raytracer in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 14 19:57:48 2017 Thomas ARBONA
** Last update Thu Mar  2 14:03:21 2017 Thomas ARBONA
*/
#include <SFML/System/Vector3.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
