/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:49:57 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/12/04 14:14:51 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//errors messages
# define ELEMS "not all map elements are accessible to the player"
# define WALLS "the map is not framed by walls"
# define CHAR2 "the map contains too much or not enough C, E or P"
# define CHAR "the map contains unauthorized characters"
# define LEN "the map is not rectangular"
# define NEWLINE "the map contains an empty newline"
# define ARGV "the map is not a correct .ber"

//xpm images
# define PATH_BG "assets/bg.xpm"
# define PATH_WALLS "assets/walls.xpm"
# define PATH_C "assets/c.xpm"
# define PATH_P "assets/p.xpm"
# define PATH_E "assets/e.xpm"
# define SQUARE 16

//others
# define BUFFER_SIZE 2
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

#endif