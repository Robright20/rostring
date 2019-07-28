/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:52:27 by fokrober          #+#    #+#             */
/*   Updated: 2019/07/28 09:30:04 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		isp(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	printab(char **s)
{
	int		i;

	i = 1;
	while (s[i])
	{
		ft_putstr(s[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr(s[0]);
}

char	**build(int i, int j, char **av)
{
	char	**s;

	s = (char **)malloc((j + 1) * sizeof(char*));
	s[j--] = 0;
	while (i)
	{
		if (!isp(av[1][i]) && isp(av[1][i - 1]))
			s[j--] = &av[1][i];
		i--;
	}
	if (!isp(av[1][i]))
		s[j] = &av[1][i];
	return (s);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;

	if (ac == 2)
	{
		i = 1;
		j = 0;
		while (av[1][i])
		{
			if (isp(av[1][i]) && !isp(av[1][i - 1]))
			{
				av[1][i] = '\0';
				j++;
			}
			i++;
		}
		if (!isp(av[1][i - 1]))
			j++;
		printab(build(i, j, av));
	}
	ft_putstr("\n");
	return (0);
}
