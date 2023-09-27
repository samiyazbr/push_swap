/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:43:06 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:25:30 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//bubble sorting in decsending order
//(bcz end of the array is treated as the top of the stack)

void sortarry(t_data *data)
{
    int n;          // Variable to store the number of elements in the array.
    int i;          // Loop variable for the outer loop.
    int j;          // Loop variable for the inner loop.
    int tmp;        // Temporary variable for swapping elements.

    n = data->topa + 1; // Set 'n' to the number of elements in the array (topa + 1).
    i = 0;              // Initialize the outer loop variable.
    while (i < n)       // Outer loop to iterate through elements of the array.
    {
        j = 0;          // Initialize the inner loop variable.
        while (j < n)   // Inner loop to compare elements in the array.
        {
            if (data->indexarray[j] > data->indexarray[i]) // Compare elements at indices 'i' and 'j'.
            {
                tmp = data->indexarray[i];                // Swap elements if 'j' is greater than 'i'.
                data->indexarray[i] = data->indexarray[j];
                data->indexarray[j] = tmp;
            }
            j++; // Move to the next element in the inner loop.
        }
        i++; // Move to the next element in the outer loop.
    }
}

void ft_sort_small(t_data *data)
{
    if (data->topa == 0)
        return; // If there are no elements in the 'a' stack, return (no sorting needed).
    else if (data->topa == 1)
        sa(data); // If there is only one element in 'a', perform 'sa' operation (swap).
    else if (data->topa == 2)
        ft_sort_three(data); // If there are two elements in 'a', call 'ft_sort_three' to sort them.
    else
    {
        // If there are more than two elements in 'a' and it's not sorted yet:
        while (data->topa > 2 && !ft_is_sorted(data))
        {
            if (ft_lowesta(data) == data->topa)
                pb(data); // If the lowest element is at the top of 'a', push it to 'b'.
            else
            {
                if (ft_lowesta(data) <= 1)
                    rra(data); // If the lowest element is closer to the bottom of 'a', rotate 'a' in reverse.
                else
                    ra(data); // Otherwise, rotate 'a'.
            }
        }
        // If 'a' is still not sorted after the above operations, recursively call 'ft_sort_small'.
        if (!ft_is_sorted(data))
            ft_sort_small(data);

        pusha(data); // Push all elements from 'b' back to 'a' (restore sorted order).
    }
}

void ft_sort_large(t_data *data)
{
    int low;
    int top;
    int high;

    low = 1; // Initialize 'low' to 1, representing the lower bound of the range to be sorted.
    top = data->topa; // Initialize 'top' to the total number of elements in 'a'.
    high = top / 2; // Initialize 'high' to half of the total number of elements in 'a'.

    // Continue sorting until the entire range is covered.
    while (low < top)
    {
        // Push elements within the current range [low, high] to stack 'b'.
        push(data, low, high);

        // Update 'low' to the next subrange.
        low = high;

        // Calculate the midpoint of the remaining range and move it slightly to the right.
        high = (high + (top - high) / 2) + 1;
    }

    // Push elements back from stack 'b' to stack 'a' in sorted order.
    pushback(data);
}

void ft_sort_three(t_data *data)
{
    // Check and perform sorting operations based on different cases.

    if (data->a[2] > data->a[1] && data->a[2] < data->a[0])
        sa(data); // If the third element is between the first and second, swap the first two elements.

    else if (data->a[2] > data->a[1] && data->a[2] > data->a[0] && data->a[1] < data->a[0])
        ra(data); // If the third element is the largest and the second is smaller than the first, rotate the stack 'a' once.

    else if (data->a[2] < data->a[1] && data->a[2] > data->a[0])
        rra(data); // If the third element is between the first and second, rotate the stack 'a' in the reverse direction once.

    else if (data->a[2] < data->a[1] && data->a[2] < data->a[0])
    {
        sa(data); // If the third element is the smallest, swap the first two elements.
        ra(data); // Then, rotate the stack 'a' once.
    }

    else if (data->a[2] > data->a[1] && data->a[2] > data->a[0])
    {
        sa(data); // If the third element is the largest, swap the first two elements.
        rra(data); // Then, rotate the stack 'a' in the reverse direction once.
    }
}
