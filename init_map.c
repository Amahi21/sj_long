/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:45:44 by amahi             #+#    #+#             */
/*   Updated: 2022/05/31 18:25:58 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_map(char **av)
{
	if (!strinstr(av[1], ".ber"))
		error("Error - invalid extantion of map");
}

int	file_linecounter(char *filename)
{
	int		linec;
	int		fd;
	int		readc;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error - file wasn't open");
	linec = 1;
	while (TRUE)
	{
		readc = read(fd, &c, 1);
		if (readc == 0)
			break ;
		if (readc < 0)
			return (-1);
		if (c == '\n')
			linec++;
	}
	close(fd);
	return (linec);
}

int	skip_n(char *filename)
{
	int		i;
	int		fd;
	char	*tmpstr;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error - file wasn't open");
	tmpstr = get_next_line(fd);
	while (tmpstr)
	{
		if (tmpstr[0] == '\n')
			i++;
		free(tmpstr);
		tmpstr = get_next_line(fd);
	}
	free(tmpstr);
	close(fd);
	return (i);
}

char	*skip_first_n(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

void	read_map(char **av, t_src *data)
{
	int		lines;
	int		tmp;
	int		fd;
	char	*tmpstr;
	int		i;

	lines = file_linecounter(av[1]) - skip_n(av[1]) - 1;
	data->mapdata = (char **)malloc(sizeof(char *) * lines);
	fd = open(av[1], O_RDONLY);
	tmpstr = skip_first_n(fd);
	i = 0;
	tmp = lines;
	while (lines > 0)
	{
		data->mapdata[i++] = filling(tmpstr, len_str(tmpstr));
		free(tmpstr);
		tmpstr = get_next_line(fd);
		lines--;
	}
	data->mapdata[i] = NULL;
	good_format(data->mapdata);
	borders(data->mapdata, tmp);
	filling_struct(data->mapdata, tmp, data);
	free(tmpstr);
}
