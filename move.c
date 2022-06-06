/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:03:51 by amahi             #+#    #+#             */
/*   Updated: 2022/06/06 15:31:43 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_of_game(t_src *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_all(data->mapdata);
	exit(0);
}

void	action(t_src *data, int x, int y, int keycode)
{
	if (!check_move(data, x, y))
	{
		data->mapdata[data->player_pos_y][data->player_pos_x] = '0';
		data->mapdata[data->player_pos_y + y][data->player_pos_x + x] = 'P';
		data->player_pos_x += x;
		data->player_pos_y += y;
		printf("player y - %d\nplayer x - %d\n\n", data->player_pos_y, data->player_pos_x);
		data->steps++;
		render(data->mapdata, data, keycode, 1);
	}
}

int	ft_move(int keycode, t_src *data)
{
	char		*score;
	int			i;
	static int	simple;

	i = 0;
	score = ft_itoa(data->collect_score);
	// write(1, "Score - ", 8);
	// while (score[i])
	// 	write(1, &score[i++], ft_strlen(score));
	// write(1, "\n", 1);
	if (keycode == W)
		action(data, 0, -1, W);
	if (keycode == A)
		action(data, -1, 0, A);
	if (keycode == S)
		action(data, 0, 1, S);
	if (keycode == D)
		action(data, 1, 0, D);
	if (keycode == ESC)
		end_of_game(data);
	if (simple % 2 == 0)
		found_enemy(data);
	simple++;
	return (1);
}
