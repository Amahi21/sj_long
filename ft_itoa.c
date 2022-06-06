/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:11:17 by amahi             #+#    #+#             */
/*   Updated: 2022/05/31 15:11:48 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	counter(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*plus(char *s, int n)
{
	int	i;

	i = (int)counter(n);
	s[i] = '\0';
	i--;
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

char	*minus(char *s, int n)
{
	int				i;
	unsigned int	num;

	i = (int)counter(n);
	s[i] = '\0';
	i--;
	s[0] = '-';
	num = n * (-1);
	while (i > 0)
	{
		s[i--] = num % 10 + '0';
		num = num / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			i;

	i = 0;
	if (n == 0)
	{
		a = (char *)malloc(2);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	a = (char *)malloc(sizeof(char) * counter(n) + 1);
	if (a == 0)
		return (0);
	if (n > 0)
		a = plus(a, n);
	if (n < 0)
		a = minus(a, n);
	return (a);
}
