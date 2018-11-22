/*
** scene.h for rt in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 15:26:42 2017 Thomas ARBONA
** Last update Sun Mar 19 20:08:08 2017 Thomas ARBONA
*/
#ifndef SCENE_H_
# define SCENE_H_

# include <SFML/Graphics/Color.h>
# include "vector.h"
# include "scene/frame/framebuffer.h"
# include "scene/ray.h"

typedef struct	s_camera
{
  t_matrix41	look_at;
  t_matrix41	look_up;
  t_matrix41	top_left;
  t_matrix41	position;
  t_matrix44	matrix;
}		t_camera;

typedef struct	s_scene
{
  t_matrix44	camera;
  float		kepsilon;
  t_framebuffer	frame;
  t_vector	objects;
  t_vector	lights;
}		t_scene;

typedef struct	s_hit
{
  float		dist;
  t_matrix41	pos;
}		t_hit;

# include "object.h"
# include "light.h"

typedef struct	s_impact
{
  t_ray		ray;
  t_hit		hit;
  sfColor	color;
  t_obj		*obj;
}		t_impact;

# define SCENE_NAME	"rt"
# define SCENE_WIDTH	800
# define SCENE_HEIGHT	800
# define SCENE_BPP	32

# define OBJECT		1
# define CAMERA		2
# define LIGHT		3

sfColor	material_getcolor(t_obj*, t_matrix41);

void	scene_init(t_scene*, char*);
void	scene_parse(t_scene*, char*);
void	scene_add(t_scene*, void*, int);
void	scene_compute(t_scene*);
void	scene_computelight(t_scene*, t_impact*, int);
void	scene_computereflection(t_scene*, t_impact*, t_ray*, int);
float	scene_intersect(t_scene*, t_ray*, t_impact*, float);
void	scene_render(t_scene*);

#endif /* !SCENE_H_ */
