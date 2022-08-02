/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:41:24 by szubair           #+#    #+#             */
/*   Updated: 2022/06/22 16:38:18 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	n;

	if (size != 0 && count > SIZE_T_MAX / size)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
	{
		return (NULL);
	}
	s = (void *)s;
	n = count * size;
	ft_bzero(s, n);
	return (s);
}
