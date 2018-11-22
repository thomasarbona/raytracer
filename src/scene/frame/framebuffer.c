/*
** framebuffer.c for render in /home/arbona/
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 15:54:36 2016 Thomas ARBONA
** Last update Sun Mar 19 21:11:06 2017 Thomas ARBONA
*/
#include <SFML/System.h>
#include <stdlib.h>
#include "scene.h"

void		framebuffer_clear(t_framebuffer *fbuff, int value)
{
  sfUint8	*pixel;
  int		index;
  int		limit;

  index = 0;
  limit = fbuff->width * fbuff->height;
  while (index != limit)
    {
      pixel = fbuff->pixels + (index * (SCENE_BPP / 8));
      pixel[0] = value;
      pixel[1] = value;
      pixel[2] = value;
      pixel[3] = 255;
      index += 1;
    }
}

int    framebuffer_init(t_framebuffer *fbuff, int width, int height)
{
  if (!(fbuff->pixels = malloc(sizeof(int) * (width * height))))
    return (0);
  fbuff->width = width;
  fbuff->height = height;
  framebuffer_clear(fbuff, 0);
  return (1);
}
