/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:42:36 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:25:08 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_data *data)
{
    int temp; // Temporary variable to store the last element of stack 'a'.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'a'.
    if (data->topa > 0)
    {
        temp = data->a[data->topa]; // Store the last element of stack 'a' in 'temp'.
        i = data->topa;

        // Shift all elements in stack 'a' to the right by one position.
        while (i > 0)
        {
            data->a[i] = data->a[i - 1];
            i--;
        }

        data->a[0] = temp; // Place the stored value at the beginning of stack 'a', completing the rotation.
    }

    write(1, "ra\n", 3); // Write "ra" to the standard output to indicate the operation.
}

void rb(t_data *data)
{
    int temp; // Temporary variable to store the last element of stack 'b'.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'b'.
    if (data->topb > 0)
    {
        temp = data->b[data->topb]; // Store the last element of stack 'b' in 'temp'.
        i = data->topb;

        // Shift all elements in stack 'b' to the right by one position.
        while (i > 0)
        {
            data->b[i] = data->b[i - 1];
            i--;
        }

        data->b[0] = temp; // Place the stored value at the beginning of stack 'b', completing the rotation.
    }

    write(1, "rb\n", 3); // Write "rb" to the standard output to indicate the operation.
}

void set_rr(t_data *data)
{
    int temp; // Temporary variable to store the last element of stack 'a' and stack 'b'.
    int i;    // Loop variable.

    // Check if there are more than 0 elements in stack 'a'.
    if (data->topa > 0)
    {
        temp = data->a[data->topa]; // Store the last element of stack 'a' in 'temp'.
        i = data->topa;

        // Shift all elements in stack 'a' to the right by one position.
        while (i > 0)
        {
            data->a[i] = data->a[i - 1];
            i--;
        }

        data->a[0] = temp; // Place the stored value at the beginning of stack 'a', completing the rotation.
    }

    // Check if there are more than 0 elements in stack 'b'.
    if (data->topb > 0)
    {
        temp = data->b[data->topb]; // Store the last element of stack 'b' in 'temp'.
        i = data->topb;

        // Shift all elements in stack 'b' to the right by one position.
        while (i > 0)
        {
            data->b[i] = data->b[i - 1];
            i--;
        }

        data->b[0] = temp; // Place the stored value at the beginning of stack 'b', completing the rotation.
    }
}

void rr(t_data *data)
{
    set_rr(data);      // Call the 'set_rr' function to perform a double rotation.
    write(1, "rr\n", 3); // Write "rr" to the standard output to indicate the 'rr' operation.
}
