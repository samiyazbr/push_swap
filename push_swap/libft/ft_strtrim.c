/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:27:06 by szubair           #+#    #+#             */
/*   Updated: 2022/05/25 13:09:48 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	while (s1[start] != '\0' && check_for_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_for_char(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
//int main()
//{
//	char a[] = "baasamiyabaab";
//	char b[] = "ba";
//	char *s = ft_strtrim(a,b);
//	printf("%s\n",s);
//}