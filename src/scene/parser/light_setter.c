/*
** light_setter.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 22:43:06 2017 Thomas ARBONA
** Last update Mon Mar 13 15:45:25 2017 Thomas ARBONA
*/
#include "scene.h"
#include "my.h"

void	parser_lightsetpos(t_light *light, char **data)
{
  sfVector3f    trans;

  trans.x = data[0] ? my_atof(data[0]) : 0.;
  trans.y = data[0] && data[1] ? my_atof(data[1]) : 0.;
  trans.z = data[0] && data[1] && data[2] ? my_atof(data[2]) : 0.;
  matrix44_translate(light->matrix, &trans);
}

void	parser_lightsetpow(t_light *light, char **data)
{
  light->power = my_atof(data[0]);
}

void	parser_lightsetcolor(t_light *light, char **data)
{
  light->color.r = data[0] ? my_getnbr(data[0]) : 0;
  light->color.g = data[0] && data[1] ? my_getnbr(data[1]) : 0;
  light->color.b = data[0] && data[1] && data[2] ? my_getnbr(data[2]) : 0;
  light->color.a = 255;
}
