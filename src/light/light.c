/*
** light.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 22:35:35 2017 Thomas ARBONA
** Last update Mon Mar 13 15:56:53 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "light.h"

t_light		*light_create()
{
  t_light	*light;

  if (!(light = malloc(sizeof(t_light))))
    return (NULL);
  matrix44_init(light->matrix);
  light->power = 1.;
  light->color = (sfColor){255, 255, 255, 255};
  return (light);
}
