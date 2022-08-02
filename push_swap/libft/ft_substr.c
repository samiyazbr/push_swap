/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:07:08 by szubair           #+#    #+#             */
/*   Updated: 2022/05/30 11:52:09 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
	{
		substr = malloc(sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	slen = ft_strlen(s) - start;
	if (slen > len)
		slen = len;
	substr = malloc(sizeof(char ) * (slen + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
//int main()
//{
//	char *a = ft_substr("tripouille", 1, 0);
//	printf("%s\n",a);
//}