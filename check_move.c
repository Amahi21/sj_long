/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:14:24 by amahi             #+#    #+#             */
/*   Updated: 2022/06/01 17:47:06 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_src *data, int x, int y)
{
	int	pos_y;
	int	pos_x;
	int	score;

	pos_x = data->player_pos_x;
	pos_y = data->player_pos_y;
	score = data->collect_score;
	if (data->mapdata[pos_y + y][pos_x + x] == '1')
		return (1);
	if (data->mapdata[pos_y + y][pos_x + x] == 'E' && score != data->score)
		return (1);
	if (data->mapdata[pos_y + y][pos_x + x] == 'C')
		data->collect_score += 1;
	if (data->mapdata[pos_y + y][pos_x + x] == 'E' && score == data->score)
		end_of_game(data);
	if (data->mapdata[pos_y + y][pos_x + x] == 'X')
		end_of_game(data);
	return (0);
}
