/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:45:27 by amahi             #+#    #+#             */
/*   Updated: 2022/05/23 10:20:13 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	filling_struct(char **map, int lines, t_src *data)
{
	int	i;
	int	j;

	data->height = lines;
	data->weight = len_str(map[0]);
	i = 0;
	data->score = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				data->score += 1;
			if (map[i][j] == 'P')
			{
				data->player_pos_x = j + 1;
				data->player_pos_y = i + 1;
			}
				j++;
		}
		i++;
	}
	data->collect_score = 0;
	data->game_over = 0;
}

void	borders(char **map, int lines)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			error("Error - invalid borders");
		i++;
	}
	i = 1;
	while (i < lines - 1)
	{
		if (map[i][0] != '1')
			error("Error - invalid borders");
		if (map[i][len_str(map[i]) - 1] != '1')
			error("Error - invalid borders");
		i++;
	}
	i = 0;
	while (map[lines - 1][i] != '\n')
	{
		if (map[lines - 1][i] != '1')
			error("Error - invalid borders");
		i++;
	}
}

int	counter_char(char **map, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				res += 1;
			j++;
		}
		i++;
	}
	return (res);
}

void	points(char **map)
{
	int	exit;
	int	start;
	int	col;

	col = counter_char(map, 'C');
	exit = counter_char(map, 'E');
	start = counter_char(map, 'P');
	if (exit < 1)
		error("Error - only one exit");
	if (start != 1)
		error("Error - only one starting position");
	if (col < 1)
		error("Error - need more collectable points");
}

void	good_format(char **map)
{
	int	i;
	int	tmp;

	tmp = len_str(map[0]);
	i = 1;
	while (map[i])
	{
		if (len_str(map[i]) != tmp)
			error("Error - invalid format of map");
		i++;
	}
	points(map);
}

		// printf("SEGA\n");