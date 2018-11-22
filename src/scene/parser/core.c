/*
** core.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Mar  7 10:40:36 2017 Thomas ARBONA
** Last update Sun Mar 19 22:28:27 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <fcntl.h>
#include "scene/parser.h"
#include "scene.h"
#include "my.h"

t_transform	g_obj_trans[] = {
  {"position", parser_objsetpos},
  {"color", parser_objsetcolor},
  {"parameter", parser_objsetparameter},
  {"rotation", parser_objsetrotation},
  {"reflection", parser_objsetreflection},
  {0, 0}
};

t_transform g_cam_trans[] = {
  {"position", parser_camsetpos},
  {"rotation", parser_camsetrotation},
  {"kepsilon", parser_camsetkepsilon},
  {0, 0}
};

t_transform g_light_trans[] = {
  {"position", parser_lightsetpos},
  {"power", parser_lightsetpow},
  {"color", parser_lightsetcolor},
  {0, 0}
};

static void		(*exec_transform(char *transform, int type))()
{
  int			index;
  t_transform		*trans;

  index = 0;
  trans = type == OBJECT ? g_obj_trans :
    type == CAMERA ? g_cam_trans :
    g_light_trans;
  if (transform == NULL)
    return (NULL);
  while (trans[index].name != 0 &&
	 my_strcmp(trans[index].name, transform) != 0)
    index += 1;
  if (trans[index].name == NULL)
    return (NULL);
  return (trans[index].func);
}

static void	scene_parseobj(t_scene *scene, int fd, char *name)
{
  t_obj		*obj;
  char		*line;
  char		**data;
  void		(*func)();

  obj = object_create(name, 1);
  while ((line = get_next_line(fd)))
    {
      if (line[0] == '#')
	continue;
      data = my_str_to_wordtab(line, ",: ");
      if (data[0] == NULL)
	break;
      if ((func = exec_transform(data[0], OBJECT)) != NULL)
	func(obj, data + 1);
    }
  scene_add(scene, obj, OBJECT);
}

static void	scene_parsecam(t_scene *scene, int fd)
{
  char		*line;
  char		**data;
  void		(*func)();

  while ((line = get_next_line(fd)))
    {
      if (line[0] == '#')
	continue;
      data = my_str_to_wordtab(line, ": ");
      if (data[0] == NULL)
	break;
      if ((func = exec_transform(data[0], CAMERA)) != NULL)
	func(scene, data + 1);
      free(line);
    }
}

static void	scene_parselight(t_scene *scene, int fd)
{
  t_light	*light;
  char		*line;
  char		**data;
  void		(*func)();

  light = light_create();
  while ((line = get_next_line(fd)))
    {
      if (line[0] == '#')
	continue;
      data = my_str_to_wordtab(line, ": ");
      if (data[0] == NULL)
	break;
      if ((func = exec_transform(data[0], LIGHT)) != NULL)
	func(light, data + 1);
      free(line);
    }
  scene_add(scene, light, LIGHT);
}

void	scene_parse(t_scene *scene, char *file)
{
  int	fd;
  char	*line;
  char	**data;

  if ((fd = open(file, O_RDONLY)) < 0)
    return;
  while ((line = get_next_line(fd)))
    {
      if (line[0] == '#' || line[0] == ' ')
	continue;
      data = my_str_to_wordtab(line, ": ");
      if (data[0] == NULL)
	continue;
      if (my_strcmp("camera", data[0]) == 0)
	scene_parsecam(scene, fd);
      else if (my_strcmp("light", data[0]) == 0)
	scene_parselight(scene, fd);
      else
	scene_parseobj(scene, fd, data[0]);
      free(line);
    }
}
