/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:24:47 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/14 11:27:36 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			str++;
			return ((char *)str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		str++;
		return ((char *)str);
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "eyupgulercan";
	char b = 'u';

	printf("%s",ft_strchr(a,b));
}*/
