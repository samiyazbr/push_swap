/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:30:00 by szubair           #+#    #+#             */
/*   Updated: 2022/05/25 13:04:55 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	ft_strlen(const char *str)
//{
//	int	c;

//	c = 0;
//	while (str[c] != '\0')
//	{
//		c++;
//	}
//	return (c);
//}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (dest == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dest, src);
	return (dest);
}
