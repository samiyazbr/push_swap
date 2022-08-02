/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:36:15 by szubair           #+#    #+#             */
/*   Updated: 2022/05/24 09:04:40 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	d;
	size_t	k;

	i = 0;
	k = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		d = 0;
		while (haystack[i + d] == needle[d] && needle[d] != '\0' && i + d < len)
		{
			d++;
		}
		if (d == k)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
//int main()
//{
//	char a[] = "aaabcabcd";
//	char b[] = "cd";
//	int i = 9;
//	char *s = ft_strnstr(a,b, i);
//	printf("%s\n",s);
//}