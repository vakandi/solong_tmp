#include "mlx_sample.h"

int main()
{
	// ----------
	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program program;
//	t_program_block program_block;
	// mlx function that initialize the mlx and returns a pointer to it.
	program.mlx = mlx_init();
	// Open a window (window.c whitin this project)
	program.window = ft_new_window(program.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "SO_LONG by vakandi");

	// ----------

	// Create a new image/sprite (image.c)
	program.sprite = ft_new_sprite(program.mlx, "andrew180.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;

//	t_image block = ft_new_sprite(program.mlx, "block.xpm");
//	mlx_put_image_to_window(program.mlx, program.window.reference, block.reference, 100, 500);
	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(program.mlx, *ft_update, &program);

	// ----------

	// mlx constant loop that keeps the detects the events
	mlx_loop(program.mlx);
}
