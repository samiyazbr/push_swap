/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:29:18 by szubair           #+#    #+#             */
/*   Updated: 2022/11/03 19:42:02 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_data *data)
{
    // Check if the top index of array 'b' is greater than or equal to 0.
    if (data->topb >= 0)
    {
        // Move an element from array 'b' to the top of array 'a'.
        data->a[data->topa + 1] = data->b[data->topb];

        // Update the top index of array 'a' and decrease the top index of array 'b'.
        data->topa += 1;
        data->topb -= 1;
    }

    // Write the string "pa\n" to the standard output (file descriptor 1).
    write(1, "pa\n", 3);
}

void pb(t_data *data)
{
    // Check if the top index of array 'a' is greater than or equal to 0.
    if (data->topa >= 0)
    {
        // Move an element from array 'a' to the top of array 'b'.
        data->b[data->topb + 1] = data->a[data->topa];

        // Update the top index of array 'b' and decrease the top index of array 'a'.
        data->topb += 1;
        data->topa -= 1;
    }

    // Write the string "pb\n" to the standard output (file descriptor 1).
    write(1, "pb\n", 3);
}
