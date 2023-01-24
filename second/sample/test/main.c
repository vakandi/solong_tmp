#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(void)
{
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Window");

    // Load the image from the file "block.xpm"
    int image_width, image_height;
    void *image = mlx_xpm_file_to_image(mlx, "block.xpm", &image_width, &image_height);
    if (!image)
    {
        fprintf(stderr, "Error: Failed to load image\n");
        return -1;
    }

    int x = 0;
    int y = 0;
    int dx = 1;
    int dy = 1;

    while (1)
    {
        mlx_clear_window(mlx, window);

        x += dx;
        y += dy;

        // Check if image has hit the window bounds
        if (x < 0 || x + image_width > WINDOW_WIDTH)
            dx = -dx;
        if (y < 0 || y + image_height > WINDOW_HEIGHT)
            dy = -dy;

        mlx_put_image_to_window(mlx, window, image, x, y);
        mlx_loop(mlx);
    }

    return 0;
}

