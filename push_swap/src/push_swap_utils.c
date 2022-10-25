/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:27:05 by szubair           #+#    #+#             */
/*   Updated: 2022/10/25 13:45:34 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(t_data *data, char *str,char **args)
{
	int i;
	long res;
	int sign;
	
	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] = '-')
		{
			sign = -1;
			i++;
		}
	}
	if(!ft_is_digit(str[i]))
		free_args(data, args);
	while(ft_isdigit(str[i]))
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if(((res > 2147483647) && (sign == 1))
			|| ((res > 2147483648) && (sign == -1)))
			free_args(data, args);
	}
	if ((!ft_isdigit(str[i]) && str[i]) || (sign == 1 && i > 12)
		|| (sign == -1 && 1 > 13))
		free_args(data, args);
	return (res * sign)
}