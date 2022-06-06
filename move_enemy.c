/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:41:27 by amahi             #+#    #+#             */
/*   Updated: 2022/06/06 18:02:08 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move_enemy(t_src *data, int x, int y)
{
	int	i;
	int	j;

	i = data->enemy_pos_y;
	j = data->enemy_pos_x;
	if (data->mapdata[i][j] == 'P')
		end_of_game(data);
	if (data->mapdata[i + y][j + x] == '1'
		|| data->mapdata[i + y][j + x] == 'C'
		|| data->mapdata[i + y][j + x] == 'E'
		|| data->mapdata[i + y][j + x] == 'X')
		return (0);
	else
		return (1);
}

void	move_enemy(t_src *data, int x, int y)
{
	int	i;
	int	j;

	i = data->enemy_pos_y;
	j = data->enemy_pos_x;
	data->mapdata[i][j] = '0';
	data->mapdata[i + y][j + x] = 'X';
	data->enemy_pos_x += x;
	data->enemy_pos_y += y;
	printf("enemy y - %d\nenemy x - %d\n", data->enemy_pos_y, data->enemy_pos_x);
	printf("------------\n");
	render(data->mapdata, data, 0, 0);
}

void	vector(t_src *data, int i, int j)
{
	if (data->player_pos_y > i && check_move_enemy(data, 0, 1))
		move_enemy(data, 0, 1);
	else if (data->player_pos_y < i && check_move_enemy(data, 0, -1))
		move_enemy(data, 0, -1);
	else if (data->player_pos_x > j && check_move_enemy(data, 1, 0))
		move_enemy(data, 1, 0);
	else if (data->player_pos_x < j && check_move_enemy(data, -1, 0))
		move_enemy(data, -1, 0);
}

void	found_enemy(t_src *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapdata[i])
	{
		j = 0;
		while (data->mapdata[i][j])
		{
			if (data->mapdata[i][j] == 'X')
			{
				data->enemy_pos_x = j;
				data->enemy_pos_y = i;
				vector(data, i, j);
			}
			j++;
		}
		i++;
	}
}
