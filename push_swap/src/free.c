/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:36:39 by szubair           #+#    #+#             */
/*   Updated: 2022/10/26 13:42:00 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	free(data->indexarray);
	free(data->a);
	free(data->b);
	write(2, "error\n", 6);
	exit (EXIT_SUCCESS);
}

void	free_args(t_data *data, char **args)
{
	int i;
	
	i = 0;
	free(data->indexarray);
	free(data->a);
	free(data->b);
	while(args[i])
	{
		free (args[i]);
		i++;
	}
	free (args);
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	ft_free(t_data *data)
{
	free(data->a);
	data->a = NULL;
	free (data->b);
	data->b = NULL;
	free(data->indexarray)
	data->indexarray = NULL;
}