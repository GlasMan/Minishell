/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:38:21 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/25 17:22:25 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **arg, int fd)
{
	int	i;
	int	fl;

	fd = fl;
	if(ft_strncmp(arg[1], "-n", 2) == 0)
	{
		i = 2;
		fl = 1;
	}
	else
	{
		i = 1;
		fl = 0;
	}
	while(arg[i])
	{
		if (arg[i][0] == '\"')
			write(1, arg[i] + 1, ft_strlen(arg[i]) - 2);
		else
			write(1, arg[i], ft_strlen(arg[i]));
		if (arg[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (fl == 0)
		write(1, "\n", 1);
}
