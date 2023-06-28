/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:35:22 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 19:07:16 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

/**
 * @brief Creates a 32-bit RGB color value with transparency.
 *
 * @param t The transparency value (0-255).
 * @param r The red component (0-255).
 * @param g The green component (0-255).
 * @param b The blue component (0-255).
 *
 * @return The resulting color value.
 */
int		create_trgb(int t, int r, int g, int b);

/**
 * @brief Retrieves the transparency value from a 32-bit RGB color value.
 *
 * @param trgb The color value.
 *
 * @return The transparency value (0-255).
 */
int		get_t(int trgb);

/**
 * @brief Retrieves the red component from a 32-bit RGB color value.
 *
 * @param trgb The color value.
 *
 * @return The red component (0-255).
 */
int		get_r(int trgb);

/**
 * @brief Retrieves the green component from a 32-bit RGB color value.
 *
 * @param trgb The color value.
 *
 * @return The green component (0-255).
 */
int		get_g(int trgb);

/**
 * @brief Retrieves the blue component from a 32-bit RGB color value.
 *
 * @param trgb The color value.
 *
 * @return The blue component (0-255).
 */
int		get_b(int trgb);

/**
 * @brief Draws a border on an image.
 *
 * @param img The image to draw on.
 */
void	draw_border(t_data img);

/**
 * @brief Draws walls on a minimap image.
 *
 * @param img The image to draw on.
 * @param x The x-coordinate of the wall.
 * @param y The y-coordinate of the wall.
 */
void	draw_walls(t_data img, int x, int y);

/**
 * @brief Draws the player on a minimap image.
 *
 * @param game The game instance.
 * @param img The image to draw on.
 */
void	draw_player(t_game *game, t_data img);

/**
 * @brief Draws the minimap.
 *
 * @param game The game instance.
 * @param img The image to draw on.
 */
void	draw_minimap(t_game *game, t_data img);

// @brief Draws a vertical line on an image. * @param img The image to draw on.
// @param x The x-coordinate of the line.
// @param se_draw An array containing
//	the start and end y-coordinatesof the line.
// @param color The color of the line.
void	draw(t_data img, int x, int *se_draw, int color);

/**
 * @brief Sets the color of a pixel in an image.
 *
 * @param data The image data.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color value to set.
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
 * @brief Locks a key event.
 *
 * @param key The key code.
 * @param game The game instance.
 *
 * @return 0
 */
int		lock_key(int key, t_game *game);

/*
 * @brief Unlocks a key event.
 *
 * @param key The key code.
 * @param game The game instance.
 *
 * @return 0
 */
int		unlock_key(int key, t_game *game);

/**
 * @brief Handles key events.
 *
 * @param game The game instance.
 *
 * @return 0
 */
int		key_events(t_game *game);

/* @brief
 * Unlocks the key and performs corresponding actions based on the key code.
 *
 * @param key   The key code.
 * @param game  Pointer to the game structure.
 * @return      0
 */
int		unlock_key(int key, t_game *game);

/* @brief
 * Handles key events and performs corresponding actions based on the key state.
 *
 * @param game  Pointer to the game structure.
 * @return      0
 */
int		key_events(t_game *game);

/**
 * @brief Moves the player up or down based on the given type.
 *
 * @param game  Pointer to the game structure.
 * @param type  Type of movement ('U' for up, 'D' for down).
 */
void	up_down(t_game *game, int type);

/**
 * @brief Moves the player right or left based on the given type.
 *
 * @param game  Pointer to the game structure.
 * @param type  Type of movement ('L' for left, 'R' for right).
 */
void	right_left(t_game *game, int type);

/**
 * @brief Rotates the player to the right.
 *
 * @param game  Pointer to the game structure.
 */
void	rotate_right(t_game *game);

/**
 * @brief Rotates the player to the left.
 *
 * @param game  Pointer to the game structure.
 */
void	rotate_left(t_game *game);

/**
 * @brief Performs actions on key press.
 *
 * @param params  Pointer to the game structure.
 * @return        0
 */
int		key_press_hook(void *params);

/**
 * @brief Sets the player position for the minimap.
 *
 * @param game  Pointer to the game structure.
 * @param y     Y-coordinate of the player.
 * @param x     X-coordinate of the player.
 */
void	minimap_posxy(t_game *game, int y, int x);

/**
 * @brief Renders the minimap.
 *
 * @param game  Pointer to the game structure.
 * @param img   The image to render the minimap on.
 */
void	minimap(t_game *game, t_data img);

/**
 * @brief Selects the color for a specific pixel on the minimap.
 *
 * @param tale  The pixel value.
 * @return      The color for the pixel.
 */
int		color_select(int tale);

/**
 * @brief Calculates the current time in milliseconds.
 *
 * @return  The current time in milliseconds.
 */
double	time_calculator(void);

/**
 * @brief Draws the background (floor and ceiling) of the game window.
 *
 * @param game  Pointer to the game structure.
 * @param img   The image to draw on.
 */
void	draw_background(t_game *game, t_data img);

/**
 * @brief Main game loop that handles ray tracing and rendering.
 *
 * @param game  The game structure.
 * @param img   The image to render the game on.
 */
void	game_loop(t_game game, t_data img);

#endif
