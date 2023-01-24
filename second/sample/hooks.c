#include "mlx_sample.h"
#include <stdio.h>
#include <tgmath.h>

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;

	// mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.reference);

	// move in a direction based on the key
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	// change color based on keys R, G and B.
	else if (key == 15)
		turn_img_to_color(&program->sprite, new_color(255,0,0,0));
	else if (key == 5)
		turn_img_to_color(&program->sprite, new_color(0,255,0,0));
	else if (key == 11)
		turn_img_to_color(&program->sprite, new_color(0,0,255,0));
	t_image block = ft_new_sprite(program->mlx, "block.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference, block.reference, 0, 500);
	mlx_put_image_to_window(program->mlx, program->window.reference, block.reference, 0, 450);
	mlx_put_image_to_window(program->mlx, program->window.reference, block.reference, 0, 400);
	mlx_put_image_to_window(program->mlx, program->window.reference, block.reference, 0, 350);
	mlx_put_image_to_window(program->mlx, program->window.reference, block.reference, 0, 300);
	// mlx function that puts and image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	
	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update (void *param)
{
    t_program		*program = (t_program *)param;
	t_program_block	*program_block = (t_program_block *)param;
    // a static that saves how many frames have passed
    static int	frame;

    // add a frame and every x frames change the position by 1 pixel
    // so it looks like its animated
    frame++;
    if (frame == ANIMATION_FRAMES)
        program->sprite_position.y += 1;
    // every x*2 frames go back that pixel to loop the animation
    else if (frame >= ANIMATION_FRAMES * 2)
    {
        program->sprite_position.y -= 1;
        frame = 0;
    }

    // Clear the window
    mlx_clear_window(program->mlx, program->window.reference);

    // Clamp the sprite position to the window bounds
    program->sprite_position.x = fmax(0, fmin(program->sprite_position.x, WINDOW_WIDTH - program->sprite.size.x));
    program->sprite_position.y = fmax(0, fmin(program->sprite_position.y, WINDOW_HEIGHT - program->sprite.size.y));

    // Draw the sprite at the clamped position
    mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	mlx_put_image_to_window(program_block->mlx, program_block->window.reference, program_block->stationary_sprite.reference, program_block->stationary_sprite_position.x, program_block->stationary_sprite_position.y);
    return (0);
}



/*
int	ft_update (void *param)
{
	t_program		*program = (t_program *)param;
	t_program_block	*program_block = (t_program_block *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	
	mlx_put_image_to_window(program_block->mlx, program_block->window.reference, program_block->stationary_sprite.reference, program_block->stationary_sprite_position.x, program_block->stationary_sprite_position.y);
	return (0);
}*/
