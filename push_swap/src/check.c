/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:31:02 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:19:15 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_check(t_data *data)
{
    // Check if there are duplicate elements in data->a array.
    if (ft_is_duplicate(data->a, data->topa))
        error(data);

    // Sort the data->a array.
    sortarry(data);

    // Check if the data->a array is sorted.
    if (!ft_is_sorted(data))
        ft_push(data); // Perform necessary operations to sort the array.

    // Free allocated memory and perform cleanup.
    ft_free(data);
}

int ft_is_duplicate(int *array, int maxindex)
{
    int i;
    int j;

    i = 0;  // Initialize an index variable 'i' to zero.

    // Outer loop: Iterate through each element in the array.
    while (i <= maxindex)
    {
        j = i + 1;  // Initialize an index variable 'j' to the next element.

        // Inner loop: Compare the current element with all subsequent elements.
        while (j <= maxindex)
        {
            // Check if the elements at index 'i' and 'j' are equal (a duplicate).
            if (array[j] == array[i])
                return (1); // Return 1 to indicate that duplicates are found.

            j++; // Move to the next element for comparison.
        }

        i++; // Move to the next element for comparison in the outer loop.
    }

    // If no duplicates are found after comparing all elements, return 0.
    return (0);
}

int ft_is_sorted(t_data *data)
{
    int i;

    i = data->topa;  // Initialize an index variable 'i' with the top index of the array.

    // Loop to iterate through the array from the top to the bottom.
    while (i != 0)
    {
        // Check if the current element at index 'i' is less than the previous element at index 'i - 1'.
        if (data->a[i] < data->a[i - 1])
            i--; // If not sorted, decrement 'i' to check the previous elements.
        else
            return (0); // If sorted, return 0 to indicate that the array is not sorted.
    }

    // If the loop completes without finding an unsorted element, return 1 to indicate that the array is sorted.
    return (1);
}
