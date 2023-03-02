// #include "mlx.h"

// int main(void)
// {
//     void *mlx;
//     void *window;
//     void *sound;
//     int sound_size;
//     char *sound_data;

//     mlx = mlx_init();
//     window = mlx_new_window(mlx, 640, 480, "My Music Player");

//     // Load music file
//     sound_data = load_music_file("music.mp3");
//     sound_size = get_music_size(sound_data);

//     // Create sound buffer
//     sound = mlx_sound_create(sound_size, 44100, 16, 2);

//     // Load audio data into sound buffer
//     mlx_sound_set_buffer(sound, sound_data, sound_size);

//     // Play sound
//     mlx_sound_play(sound);

//     mlx_loop(mlx);

//     return 0;
// }
// This is just a basic example of how to play music using minilibx. You may need to modify it to fit your specific needs and ensure that it meets the requirements of the 42's school norm.




