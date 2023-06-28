/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:42:33 by bgales            #+#    #+#             */
/*   Updated: 2023/06/27 19:12:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "cub3d.h"

/**
 * @brief Calculates the absolute value of a given value.
 *
 * @param value The input value.
 * @return The absolute value of the input.
 */
double			v_abs(double value);

/**
 * @brief Initializes the delta distance based on the given values.
 *
 * @param d The delta distance.
 * @param r The input value.
 * @return The initialized delta distance.
 */
double			delta_dist_init(double d, double r);

/* @brief
 * Calculates the ray direction based on the game and calculation parameters.
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 */
void			ray_dir_calc(t_game game, t_calc *n);

/* @brief
	Determines if a wall has been hit and
		updates the calculation parameters accordingly.
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 */
void			hit_wall(t_game game, t_calc *n);

/* @brief
	Performs the last calculations for rendering
		the game and updates the game and calculation parameters accordingly.
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 * @param img The image data.
 */
void			last_calcul(t_game *game, t_calc *n, t_data img);

/**
 * @brief Initializes the camera direction based on the game instance.
 *
 * @param game The game instance.
 */
void			init_camera_dir(t_game *game);

/**
 * @brief Initializes the keys of the game instance.
 * @param game The game instance.
 */
void			init_keys(t_game *game);

/**
 * @brief Initializes the game parameters related to the player's position.
 *
 * @param game The game instance.
 */
void			init_numig(t_game *game);

/*
	@brief Initializes the game loop with
		the given game and calculation parameters.
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 */
void			game_loop_init(t_game game, t_calc *n);

/**
 * @brief Performs the last calculations
 * 	for rendering the game and updates the game and calculation parameters
 * 	accordingly (helper function).
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 * @param img The image data.
 * @param step The step value.
 */
void			last_calc_norm(t_game *game,
					t_calc *n, t_data img, double step);

/**
 * @brief Sets the image data based on the given path.
 *
 * @param game The game instance.
 * @param img The image data.
 * @param path The path to the image file.
 */
void			set_image(t_game *game, t_data *img, char *path);

/**
 * @brief Retrieves the color value at the given position from the image data.
 *
 * @param data The image data.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param addr The address of the image data.
 * @return The color value at the given position.
 */
unsigned int	get_data_color(t_data *data, int x, int y, void *addr);

/**
 * @brief Tests the texture and retrieves the corresponding pixel color.
 *
 * @param game The game instance.
 * @param n The calculation parameters.
 * @return The color value of the pixel in the texture.
 */
unsigned int	test_texture(t_game *game, t_calc *n);

/**
 * @brief Retrieves the path from the given string.
 *
 * @param str The input string.
 * @return The extracted path.
 */
char			*get_path(char *str);

/**
 * @brief Initializes the textures based on the game instance.
 *
 * @param game The game instance.
 */
void			texture_init(t_game *game);

#endif
