/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:45:40 by amahi             #+#    #+#             */
/*   Updated: 2022/06/03 16:36:31 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strinstr(char *big, char *small)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i])
	{
		j = 0;
		while (big[i] == small[j])
		{
			if (small[j] == '\0')
				return (1);
			i++;
			j++;
		}
		i++;
	}
	return (0);
}

char	*filling(char *in, int len)
{
	int		i;
	char	*out;

	i = 0;
	out = (char *)malloc(sizeof(char) * len);
	while (in[i])
	{
		if (in[i] == '\n')
		{
			out[i] = '\0';
			break ;
		}
		else
			out[i] = in[i];
		i++;
	}
	out[i] = in[i];
	return (out);
}

int	len_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
		i++;
	return (i);
}

void	free_all(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}
