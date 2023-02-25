#include "includes/cub3d.h"

#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2

int key_press_hook(int keycode)
{
    if (keycode == KEY_W)
    {
        printf("Pressed W\n");
    }
    else if (keycode == KEY_S)
    {
        printf("Pressed S\n");
    }
    else if (keycode == KEY_A)
    {
        printf("Pressed A\n");
    }
    else if (keycode == KEY_D)
    {
        printf("Pressed D\n");
    }
    return (0);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    // Initialize the Minilibx library
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "WSAD Key Event Example");

    // Set the key event hook
    mlx_hook(win_ptr, 2, 0, key_press_hook, NULL);

    // Start the main loop
    mlx_loop(mlx_ptr);

    return (0);
}




int key_press_hook(int keycode, void *param)
{
    int *my_data = (int *)param;

    // Do something with my_data...

    return (0);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int my_data = 42;

    // Initialize the Minilibx library
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "WSAD Key Event Example");

    // Set the key event hook and pass my_data as the param argument
    mlx_hook(win_ptr, 2, 0, key_press_hook, &my_data);

    // Start the main loop
    mlx_loop(mlx_ptr);

    return (0);
}
