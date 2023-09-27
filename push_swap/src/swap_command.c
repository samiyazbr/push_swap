/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:53:31 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:26:20 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_data *data)
{
    int temp;

    // Check if there is more than one element in stack 'a'.
    if (data->topa > 0)
    {
        // Swap the top two elements of stack 'a'.
        temp = data->a[data->topa];
        data->a[data->topa] = data->a[data->topa - 1];
        data->a[data->topa - 1] = temp;
    }

    // Write "sa" to the standard output to indicate the operation.
    write(1, "sa\n", 3);
}

void sb(t_data *data)
{
    int temp;

    // Check if there is more than one element in stack 'b'.
    if (data->topb > 0)
    {
        // Swap the top two elements of stack 'b'.
        temp = data->b[data->topb];
        data->b[data->topb] = data->b[data->topb - 1];
        data->b[data->topb - 1] = temp;
    }

    // Write "sb" to the standard output to indicate the operation.
    write(1, "sb\n", 3);
}

void ss(t_data *data)
{
    // Call the 'sa' function to swap the top two elements of stack 'a'.
    sa(data);

    // Call the 'sb' function to swap the top two elements of stack 'b'.
    sb(data);

    // Write "ss" to the standard output to indicate the operation.
    write(1, "ss\n", 3);
}
