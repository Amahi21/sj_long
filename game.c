/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:22:22 by amahi             #+#    #+#             */
/*   Updated: 2022/06/03 16:36:05 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*chose_img(int key)
{
	if (key == W)
		return ("textures/Ship_up.xpm");
	if (key == A)
		return ("textures/Ship_left.xpm");
	if (key == S)
		return ("textures/Ship_down.xpm");
	if (key == D)
		return ("textures/Ship_right.xpm");
	return (NULL);
}

void	init_img(t_src *data, int key)
{
	int		wight;
	int		height;
	char	*tmp;

	tmp = "textures/Ground.xpm";
	data->ground = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
	tmp = "textures/Wall2.xpm";
	data->wall = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
	if (data->collect_score != data->score)
		tmp = "textures/Exit1.xpm";
	else
		tmp = "textures/Exit2.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
	tmp = chose_img(key);
	data->player = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
	tmp = "textures/Enemy_ship_left.xpm";
	data->enemy = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
}

void	past_img(char c, t_src *data, int i, int j)
{
	i *= 64;
	j *= 64;
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j, i);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, j, i);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->ground, j, i);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, j, i);
	if (c == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy, j, i);
}

void	render(char **map, t_src *data, int keycode, int f)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (f == 1)
		init_img(data, keycode);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			past_img(map[i][j], data, i, j);
			j++;
		}
		i++;
	}
	str = ft_itoa(data->steps);
	mlx_string_put(data->mlx, data->win, 60, 20, -1, str);
	free(str);
}

void	painting(t_src *data)
{
	int		weight;
	int		height;
	int		size;

	size = 64;
	weight = data->weight * 64;
	height = data->height * 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, weight, height, "so_long");
	render(data->mapdata, data, 0, 1);
}
