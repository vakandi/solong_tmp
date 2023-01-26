#include <mlx.h>
#include <string.h>
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 800

int main()
{
    // Initialize minilibx
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Video");
    int frame_count = 82;
    int delay = 1000/10; // 10 frames per second
    char frame_name[20];
    int i;
    for (i = 1; i <= frame_count; i++) {
        sprintf(frame_name, "ezgif-frame-%03d.jpg", i);
        void *img = mlx_xpm_file_to_image(mlx, frame_name);
        mlx_put_image_to_window(mlx, win, img, 0, 0);
        mlx_destroy_image(mlx, img);
        mlx_loop_hook(mlx, &frame_display_loop, &img);
        mlx_loop(mlx);
        usleep(delay*1000);
    }
    // Close the window and exit
    mlx_destroy_window(mlx, win);
    return 0;
}

