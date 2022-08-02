/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:53:31 by szubair           #+#    #+#             */
/*   Updated: 2022/08/02 09:06:07 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all, int flag)
{
	int	tmp;
	
	if (all->size_a < 2)
		return ;
	tmp = all->stack_a->index;
	all->stack_a->index = all->stack_a->next->index;
	all->stack_a->next->index = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_all *all, int flag)
{
	int	tmp;
	
	if (all->size_b < 2)
		return ;
	tmp = all->stack_b->index;
	all->stack_b->index = all->stack_b->next->index;
	all->stack_b->next->index = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_all *all)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		sa(all, 0);
		sb(all,0);
		write (1, "ss\n", 3);
	}
}