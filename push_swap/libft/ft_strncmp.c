/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:24:51 by szubair           #+#    #+#             */
/*   Updated: 2022/05/24 09:03:50 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] != '\0' && b[i] != '\0' && i < n)
	{
		if (a[i] > b[i])
			return (1);
		if (b[i] > a[i])
			return (-1);
		if (a[i] == b[i])
		{
			i++;
		}
	}
	if (i == n)
		return (0);
	if (a[i] != '\0')
		return (1);
	if (b[i] != '\0')
		return (-1);
	return (0);
}
