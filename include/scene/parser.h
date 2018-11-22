/*
** parser.h for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar  8 16:12:57 2017 Thomas ARBONA
** Last update Wed Mar 15 15:52:25 2017 Thomas ARBONA
*/
#ifndef PARSER_H_
# define PARSER_H_

typedef struct	s_transform
{
  char		*name;
  void		(*func)();
}		t_transform;

void	parser_objsetpos();
void	parser_objsetcolor();
void	parser_objsetparameter();
void	parser_objsetrotation();
void	parser_objsetreflection();

void	parser_camsetpos();
void	parser_camsetrotation();
void	parser_camsetkepsilon();

void	parser_lightsetpos();
void	parser_lightsetpow();
void	parser_lightsetcolor();

#endif /* !PARSER_H_ */
