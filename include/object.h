/*
** object.h for rt in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Feb 28 15:13:10 2017 Thomas ARBONA
** Last update Sun Mar 19 20:43:08 2017 Thomas ARBONA
*/
#ifndef OBJECT_H_
# define OBJECT_H_

# include <SFML/Graphics/Color.h>
# include "object/sphere.h"
# include "object/plane.h"
# include "object/cylinder.h"
# include "object/triangle.h"
# include "object/cone.h"
# include "matrix.h"

# define OBJ_MAX_ARGS	4

typedef struct	s_objfunc
{
  char		*token;
  int		nb_args;
  void		*(*create)();
  void		(*intersect)();
  void		(*update)();
  void		(*getnormal)();
}		t_objfunc;

# define MAT_WOOD	1
# define MAT_PERLIN	2

# define WOOD_C1	((sfColor){255, 0, 0, 255})
# define WOOD_C2	((sfColor){182, 155, 76, 255})
# define WOOD_C3	((sfColor){130, 82, 1, 255})
# define WOOD_C4	((sfColor){0, 100, 100, 255})

typedef struct	s_obj
{
  void		*data;
  sfColor	color;
  float		reflection;
  int		material;
  float		perlin;
  t_matrix44	matrix;
  t_matrix44	matrix_inv;
  void		(*intersect)();
  void		(*update)();
  void		(*getnormal)();
}		t_obj;

# define SPHERE		(1 << 0)

t_obj	*object_create(char*, ...);
void	object_gethitpoint();

#define FLOOR(x)	(((x) >= 0) ? (int)(x) : (int)(x) - 1)

float	__attribute__ ((pure)) get_perlin(float x, float y, float z);

#endif /* !OBJECT_H_ */
