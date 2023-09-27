/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:53:46 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:24:15 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_data *data)
{
    int temp; // Temporary variable to store the first element of stack 'a'.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'a'.
    if (data->topa > 0)
    {
        temp = data->a[0]; // Store the first element of stack 'a' in 'temp'.
        i = 0;

        // Shift all elements in stack 'a' to the left by one position.
        while (i < data->topa)
        {
            data->a[i] = data->a[i + 1];
            i++;
        }

        data->a[data->topa] = temp; // Place the stored value at the end of stack 'a'.
    }
    
    write(1, "rra\n", 4); // Write "rra" to the standard output to indicate the operation.
}

void rrb(t_data *data)
{
    int temp; // Temporary variable to store the first element of stack 'b'.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'b'.
    if (data->topb > 0)
    {
        temp = data->b[0]; // Store the first element of stack 'b' in 'temp'.
        i = 0;

        // Shift all elements in stack 'b' to the left by one position.
        while (i < data->topb)
        {
            data->b[i] = data->b[i + 1];
            i++;
        }

        data->b[data->topb] = temp; // Place the stored value at the end of stack 'b'.
    }
    
    write(1, "rrb\n", 4); // Write "rrb" to the standard output to indicate the operation.
}

void rrr(t_data *data)
{
    int temp; // Temporary variable to store the first element of stack 'b' or 'a', depending on the case.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'b'.
    if (data->topb > 0)
    {
        temp = data->b[0]; // Store the first element of stack 'b' in 'temp'.
        i = 0;

        // Shift all elements in stack 'b' to the left by one position.
        while (i < data->topb)
        {
            data->b[i] = data->b[i + 1];
            i++;
        }

        data->b[data->topb] = temp; // Place the stored value at the end of stack 'b'.
    }

    // Check if there are more than 0 elements in stack 'a'.
    if (data->topa > 0)
    {
        temp = data->a[0]; // Store the first element of stack 'a' in 'temp'.
        i = -1;

        // Shift all elements in stack 'a' to the left by one position.
        while (++i < data->topa)
        {
            data->a[i] = data->a[i + 1];
        }

        data->a[data->topa] = temp; // Place the stored value at the end of stack 'a'.
    }
    
    write(1, "rrr\n", 4); // Write "rrr" to the standard output to indicate the operation.
}
