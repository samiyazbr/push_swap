/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:19:26 by szubair           #+#    #+#             */
/*   Updated: 2022/10/28 13:21:45 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_check_arg(t_data *data, char *str)
{
	int		i;
	char	**args;

	args = ft_split(str, ' ');
	free (str);
	initialize (data, args);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free (args);
}

void	initialize(t_data *data, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
		i++;
	data->indexarray = (int *)malloc(sizeof(int) * i);
	data->a = (int *)malloc(sizeof(int) * i);
	data->b = (int *)malloc(sizeof(int) * i);
	if (!data->indexarray || !data->a || !data->b)
		error(data);
	j = 0;
	i--;
	while (i >= 0)
	{
		data->indexarray[j] = ft_atoi(data, av[i], av);
		data->a[j++] = ft_atoi(data, av[i--], av);
	}
	data->topa = j - 1;
	data->topb = -1;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	char	*str;
	int		flag;

	str = "";
	if (ac == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	flag = 0;
	while (av[i])
	{
		str = ft_strjoin(str, av[i], flag);
		flag = 1;
		i++;
	}
	double_check_arg(&data, str);
	ft_check(&data);
	return (0);
}
