/*
** cam_setter.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Mar  9 22:10:19 2017 Thomas ARBONA
** Last update Wed Mar 15 15:51:51 2017 Thomas ARBONA
*/
#include "scene.h"
#include "my.h"

void	parser_camsetpos(t_scene *scene, char **data)
{
  sfVector3f    trans;

  trans.x = data[0] ? my_atof(data[0]) : 0.;
  trans.y = data[0] && data[1] ? my_atof(data[1]) : 0.;
  trans.z = data[0] && data[1] && data[2] ? my_atof(data[2]) : 0.;
  matrix44_translate(scene->camera, &trans);
}

void	parser_camsetrotation(t_scene *scene, char **data)
{
  sfVector3f    rot;

  rot.x = data[0] ? my_atof(data[0]) : 0.;
  rot.y = data[0] && data[1] ? my_atof(data[1]) : 0.;
  rot.z = data[0] && data[1] && data[2] ? my_atof(data[2]) : 0.;
  matrix44_rotate(scene->camera, &rot);
}

void	parser_camsetkepsilon(t_scene *scene, char **data)
{
  scene->kepsilon = my_atof(data[0]);
}
