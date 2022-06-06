/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:49:45 by amahi             #+#    #+#             */
/*   Updated: 2022/06/03 16:41:40 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_pizza(t_src *data, int t, int i, int j)
{
	char	*tmp;
	int		wight;
	int		height;

	if (t >= 0 && t < 10)
		tmp = "textures/Pizza.xpm";
	if (t >= 10 && t < 20)
		tmp = "textures/Pizza1.xpm";
	if (t >= 20 && t < 30)
		tmp = "textures/Pizza2.xpm";
	if (t >= 30 && t < 40)
		tmp = "textures/Pizza3.xpm";
	if (t >= 40 && t < 50)
		tmp = "textures/Pizza4.xpm";
	if (t >= 50 && t < 60)
		tmp = "textures/Pizza5.xpm";
	if (t == 30)
	data->items = 0;
	data->items = mlx_xpm_file_to_image(data->mlx, tmp, &wight, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->items, j * 64, i * 64);
}

void	search_img(t_src *data, int t)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapdata[i])
	{
		j = 0;
		while (data->mapdata[i][j])
		{
			if (data->mapdata[i][j] == 'C')
				animation_pizza(data, t, i, j);
			j++;
		}
		i++;
	}
}

int	animation(t_src *data)
{
	static int	f;

	if (data->anim <= 60 && f == 0)
	{
		search_img(data, data->anim++);
		if (data->anim == 60)
			f = 1;
	}
	if (data->anim >= 0 && f == 1)
	{
		search_img(data, data->anim);
		data->anim--;
		if (data->anim == 0)
			f = 0;
	}
	return (0);
}
