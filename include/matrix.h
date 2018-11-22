/*
** matrix.h for matrix in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Feb 22 15:22:07 2017 Thomas ARBONA
** Last update Thu Mar 16 16:05:46 2017 Thomas ARBONA
*/

#ifndef MATRIX_H_
# define MATRIX_H_

# include <SFML/System/Vector3.h>

typedef	float	t_matrix44[4][4];
typedef float	t_matrix33[3][3];
typedef float	t_matrix41[4];

void		matrix44_init(t_matrix44);
void		matrix41_init(t_matrix41);
void		matrix44_translate(t_matrix44, sfVector3f*);
void		matrix44_multiply44(t_matrix44, t_matrix44, t_matrix44);
void		matrix44_multiply41(t_matrix41, t_matrix44, t_matrix41);
void		matrix44_inverse(t_matrix44, t_matrix44);
void		matrix44_rotate(t_matrix44, sfVector3f*);
void		matrix44_copy(t_matrix44, t_matrix44);
void		matrix41_copy(t_matrix41, t_matrix41);
void		matrix41_cross(t_matrix41, t_matrix41, t_matrix41);

void		matrix44_debug(t_matrix44);
void		matrix41_debug(t_matrix41);

# define X	0
# define Y	1
# define Z	2
# define W	3

#endif /* !MATRIX_H_ */
