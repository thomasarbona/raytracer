/*
** main.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 15:44:27 2017 Thomas ARBONA
** Last update Sun Mar 19 20:50:06 2017 Thomas ARBONA
*/
#include <stdio.h>
#include "scene.h"
#include "object.h"

int		main(int ac, char **av)
{
  t_scene	scene;

  scene_init(&scene, ((ac > 1) ? av[1] : NULL));
  printf("rendering...");
  fflush(stdout);
  scene_compute(&scene);
  printf("done!\n");
  scene_render(&scene);
  return (0);
}
