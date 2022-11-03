/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:36:39 by szubair           #+#    #+#             */
/*   Updated: 2022/11/03 19:22:43 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	free (data->indexarray);
	free (data->a);
	free (data->b);
	write(2, "Error\n", 6);
	exit (0);
}


void	free_args(t_data *data, char **args)
{
	int	i;

	i = 0;
	free (data->indexarray);
	free (data->a);
	free (data->b);
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free(args);
	write(2, "Error\n", 6);
	exit (0);
}


void	ft_free(t_data *data)
{
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
	free(data->indexarray);
	data->indexarray = NULL;
}