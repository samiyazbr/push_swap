/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:45:12 by szubair           #+#    #+#             */
/*   Updated: 2022/05/25 13:08:51 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destination;
	const char	*source;
	size_t		i;

	source = (const char *)src;
	destination = (char *)dst;
	i = 0;
	if (dst == src)
	{
		return (dst);
	}
	if (destination > source)
	{
		while (len--)
		{
			destination[len] = source[len];
		}
		return (dst);
	}
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
