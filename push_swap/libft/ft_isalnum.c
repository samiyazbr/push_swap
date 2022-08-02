/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:00:38 by szubair           #+#    #+#             */
/*   Updated: 2022/05/14 12:36:34 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	ft_isalpha(int c)
//{
//	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
//}

//int	ft_digit(int c)
//{
//	return (c >= '0' && c <= '9');
//}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
