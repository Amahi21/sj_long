/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:48:55 by amahi             #+#    #+#             */
/*   Updated: 2022/05/31 17:42:25 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*filling_one_str(int fd, char *one_str)
{
	char	*buff;
	int		bwr;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bwr = 1;
	while (!ft_strchr(one_str, '\n') && bwr)
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		if (bwr < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bwr] = '\0';
		one_str = ft_strjoin(one_str, buff);
	}
	free(buff);
	return (one_str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*one_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	one_str = filling_one_str(fd, one_str);
	if (!one_str)
		return (NULL);
	result = filling_result(one_str);
	one_str = cat_one_str(one_str);
	return (result);
}
