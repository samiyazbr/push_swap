/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:43:20 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:21:34 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_data *data)
{
    // Check if the size of stack 'a' is less than 5.
    if (data->topa < 5)
        ft_sort_small(data);  // If the stack size is small, use a small sorting algorithm.
    else if (data->topa <= 500)
    {
        ft_sort_large(data);  // If the stack size is moderate, use a large sorting algorithm.
        
        // Rotate 'a' until the smallest element is at the top.
        while (ft_lowesta(data) != data->topa)
            rra(data);
    }
}

void push(t_data *data, int min, int max)
{
    int i;

    i = max - min;

    // Enter a loop to push elements from stack 'a' to stack 'b'.
    while (i != 0)
    {
        // Check if the top element of stack 'a' is within the specified range [min, max].
        if (data->a[data->topa] < data->indexarray[max] && data->a[data->topa] >= data->indexarray[min])
        {
            pb(data); // Push the top element of stack 'a' to stack 'b'.
            i--;     // Decrement the counter of elements to push.
        }
        else
            ra(data); // Rotate the elements in stack 'a' (move the top element to the bottom).
    }
}

void pusha(t_data *data)
{
    // Enter a loop to push elements from stack 'b' to stack 'a'.
    while (data->topb >= 0)
        pa(data); // Push the top element of stack 'b' to stack 'a'.
}

void pushback(t_data *data)
{
    int x;

    x = 1;

    // Enter a loop to push elements back to stack 'a' from stack 'b'.
    while (data->topb >= 0)
    {
        if (x == 1)
            x = get_values(data);

        // Check if the best value is at the top of stack 'b', and push it to stack 'a'.
        if (data->bestvalue == data->b[data->topb])
            push_to_a(data, &x);
        else
        {
            // Check different cases for rotating and pushing elements from stack 'b' to stack 'a'.
            if (data->bestindex > data->topb / 2 && data->correctadd > data->topa / 2 && data->correctvalue != data->a[data->topa])
                rr(data);
            else if (data->bestindex <= data->topb / 2 && data->correctadd <= data->topa / 2 && data->correctvalue != data->a[data->topa])
                rrr(data);
            else if (data->bestindex > data->topb / 2)
                rb(data);
            else
                rrb(data);
        }
    }
}

void push_to_a(t_data *data, int *x)
{
    // Check if the correct value is already at the top of stack 'a'.
    if (data->correctvalue == data->a[data->topa])
    {
        pa(data); // Push the correct value to stack 'a'.
        *x = 1;   // Update the value of 'x' to 1.
    }
    else
    {
        // Check the position of the correct value in stack 'a' and perform a rotation accordingly.
        if (data->correctadd > data->topa / 2)
            ra(data); // Rotate stack 'a' to the right.
        else
            rra(data); // Rotate stack 'a' to the left.
    }
}
