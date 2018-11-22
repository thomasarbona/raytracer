/*
** render.c for rt in /home/arbona/tek1/MUL/raytracer1
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Mar  1 10:42:03 2017 Thomas ARBONA
** Last update Sun Mar 19 23:03:06 2017 Thomas ARBONA
*/
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "scene.h"
#include "my.h"

static void		scene_loop(sfRenderWindow *window)
{
  sfEvent		event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
  	{
  	  if (event.key.code == sfKeyEscape)
  	    sfRenderWindow_close(window);
  	}
    }
}

void			scene_render(t_scene *scene)
{
  sfVideoMode		mode;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfRenderWindow	*window;

  mode.width = SCENE_WIDTH;
  mode.height = SCENE_HEIGHT;
  mode.bitsPerPixel = SCENE_BPP;
  if (!(window = sfRenderWindow_create(mode, SCENE_NAME, sfClose, NULL)))
    return;
  texture = sfTexture_create(mode.width, mode.height);
  sprite = sfSprite_create();
  sfTexture_updateFromPixels(texture, scene->frame.pixels,
			     scene->frame.width, scene->frame.height, 0, 0);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
  scene_loop(window);
}
