/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:45:31 by amahi             #+#    #+#             */
/*   Updated: 2022/05/23 12:58:26 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;

typedef struct s_src
{
	int		height;
	int		weight;

	int		player_pos_x;
	int		player_pos_y;

	int		score;
	int		collect_score;

	char	**mapdata;

	void	*wall;
	void	*exit;
	void	*items;
	void	*player;

	int		enemy_pos;

	int		game_over;

}	t_src;


typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

// GNL / get_next_line.c
char	*get_next_line(int fd);

// GNL / get_next_line_utils.c
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int ch);
char	*filling_result(char *one_str);
char	*cat_one_str(char *one_str);

// src.c
int		strinstr(char *big, char *small);
char	*filling(char *in, int len);
int		len_str(char *str);

// main.c
void	error(char *text);

// init_map.c
void	read_map(char **av, t_src *data);

// check_map.c
void	borders(char **map, int lines);
void	good_format(char **map);
void	filling_struct(char **map, int lines, t_src *data);

// game.c
void	painting(t_src *data);

// out.c
void	out_str(char *str);
void	out_2p(char **mass);

#endif	// SO_LONG_H
