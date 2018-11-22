/*
** scene.c for rt in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 15:29:08 2017 Thomas ARBONA
** Last update Wed Mar 15 15:55:11 2017 Thomas ARBONA
*/
#include "object.h"
#include "scene.h"
#include "matrix.h"
#include "vector.h"

void	scene_init(t_scene *scene, char *file)
{
  vector_init(&scene->objects);
  vector_init(&scene->lights);
  matrix44_init(scene->camera);
  scene->kepsilon = 0.0;
  framebuffer_init(&scene->frame, SCENE_WIDTH, SCENE_HEIGHT);
  if (file != NULL)
    scene_parse(scene, file);

}

void		scene_add(t_scene *scene, void *el, int type)
{
  t_obj		*obj;
  t_light	*light;

  if (type == OBJECT)
    {
      obj = (t_obj*)el;
      matrix44_inverse(obj->matrix_inv, obj->matrix);
      vector_push(&scene->objects, obj);
    }
  else if (type == LIGHT)
    {
      light = (t_light*)el;
      vector_push(&scene->lights, light);
    }
}
