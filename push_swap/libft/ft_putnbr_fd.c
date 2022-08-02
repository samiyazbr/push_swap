/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:03:54 by szubair           #+#    #+#             */
/*   Updated: 2022/05/30 11:07:50 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_putchar_fd(char c, int fd)
//{
//	write(fd, &c, 1);
//}

void	ft_putnbr_fd(int d, int fd)
{
	if (d == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		ft_putchar_fd('-', fd);
		d = -d;
	}
	if (d >= 0 && d <= 9)
		ft_putchar_fd(d + '0', fd);
	if (d > 9)
	{
		ft_putnbr_fd(d / 10, fd);
		ft_putnbr_fd(d % 10, fd);
	}
}
