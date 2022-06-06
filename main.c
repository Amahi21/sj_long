/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:29:48 by amahi             #+#    #+#             */
/*   Updated: 2022/06/01 15:18:11 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *text)
{
	int	i;

	i = 0;
	while (text[i])
		write(1, &text[i++], 1);
	write(1, "\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_src	*data;

	if (ac == 2)
	{
		data = (t_src *)malloc(sizeof(t_src));
		if (!data)
			error("Error - malloc");
		data->steps = 0;
		read_map(av, data);
		painting(data);
		data->anim = 0;
		mlx_loop_hook(data->mlx, animation, data);
		mlx_hook(data->win, KEYDOWN, 1L<<0, ft_move, data);
		mlx_loop(data->mlx);
	}
	else
		error("Error - invalid input\nCorrect: ./so_long ./[way to map]");
}
