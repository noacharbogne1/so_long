/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:49:57 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/12/09 16:36:07 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//errors messages
# define MAP "the map is too large"
# define FD "permission denied"
# define ELEMS "not all map elements are accessible to the player"
# define WALLS "the map is not framed by walls"
# define CHAR2 "the map contains too much or not enough C, E or P"
# define CHAR "the map contains unauthorized characters"
# define LEN "the map is not rectangular"
# define NEWLINE "the map contains an empty newline"
# define ARGC "there is not 2 arguments"
# define ARGV "the map is not a correct .ber"
# define BG "the background image could not be loaded"
# define WALLS_IMG "the walls image could not be loaded"
# define P "the player image could not be loaded"
# define C "the collectible image could not be loaded"
# define E "the exit image could not be loaded"
# define MLX "the initialisation of MLX failed"
# define RENDER "the rendering of the assets failed"

//xpm images
# define PATH_BG "assets/bg.xpm"
# define PATH_WALLS "assets/walls.xpm"
# define PATH_C "assets/c.xpm"
# define PATH_P "assets/p.xpm"
# define PATH_E "assets/e.xpm"
# define TS 32

//others
# define BUFFER_SIZE 2

#endif