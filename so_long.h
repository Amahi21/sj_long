/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:45:31 by amahi             #+#    #+#             */
/*   Updated: 2022/06/03 16:39:57 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define BUFFER_SIZE 1
# define KEYDOWN 2
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_src
{
	int		height;
	int		weight;

	int		player_pos_x;
	int		player_pos_y;

	int		enemy_pos_x;
	int		enemy_pos_y;

	int		score;
	int		collect_score;

	char	**mapdata;
	void	*mlx;
	void	*win;
	int		steps;
	int		anim;

	void	*wall;
	void	*exit;
	void	*ground;
	void	*items;
	void	*player;
	void	*enemy;

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
int		ft_atoi(const char *str);
void	free_all(char **mass);

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
void	render(char **map, t_src *data, int keycode, int f);

// move.c
int		ft_move(int keycode, t_src *data);
void	end_of_game(t_src *data);

// check_move.c
int		check_move(t_src *data, int x, int y);

// ft_itoa.c
char	*ft_itoa(int n);

// animation.c
int		animation(t_src *data);

// out.c
void	out_str(char *str);
void	out_2p(char **mass);

// move_enemy.c
void	found_enemy(t_src *data);

#endif	// SO_LONG_H
