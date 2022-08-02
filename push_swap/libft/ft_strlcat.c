/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:02:24 by szubair           #+#    #+#             */
/*   Updated: 2022/07/15 10:33:51 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	b;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	b = len_dst;
	while (b + 1 < dstsize && i < len_src)
	{
		dst[b] = src[i];
		i++;
		b++;
	}
	if (dstsize != 0 && b  + 1 < dstsize)
	{
		dst[b] = '\0';
	}
	if (dstsize > len_dst)
		return (len_dst + len_src);
	else
		return (dstsize + len_src);
}