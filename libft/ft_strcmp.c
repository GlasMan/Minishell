/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:54:59 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/25 16:44:49 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *arr, char *arr1)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != arr1[i])
			return (-1);
		i++;
	}
	if (arr1[i] != '\0')
		return (-1);
	return (0);
}
