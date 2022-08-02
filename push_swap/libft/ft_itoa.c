/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:49:11 by szubair           #+#    #+#             */
/*   Updated: 2022/05/25 11:10:47 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*s;
	size_t			len;

	len = count(n);
	num = n;
	if (n < 0)
	{
		num = -1 * n;
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (num == 0)
		s[--len] = 0 + '0';
	while (num)
	{
		s[--len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
//int main()
//{
//	int a = -123;
//	char *s = ft_itoa(a);
//	printf("%s\n", s);
//}