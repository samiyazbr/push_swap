/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:11:45 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:21:12 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_correct_index_on_a(t_data *data, int index)
{
    int i;

    i = data->topa;  // Initialize an index variable 'i' with the top index of array 'a'.

    // Loop to iterate through the elements of array 'a' from top to bottom.
    while (i > 0)
    {
        // Check if the element in array 'b' at the given 'index' is greater than
        // the element in array 'a' at index 'i' and less than the element in array 'a' at index 'i - 1'.
        if (data->b[index] > data->a[i] && data->b[index] < data->a[i - 1])
            return (i - 1);  // Return the index 'i - 1' as the correct index on array 'a'.
        i--;  // Decrement 'i' to check the previous elements in array 'a'.
    }

    // If no suitable index is found, return 'data->topa' as the default index on array 'a'.
    return (data->topa);
}

int ft_moves(t_data *data, int i)
{
    int moves;
    int sortedindex;

    moves = 0;  // Initialize the 'moves' variable to zero.

    // Check if 'i' is less than half of the top index of array 'b'.
    if (i < data->topb / 2)
        moves += i;  // If true, add 'i' to 'moves'.
    else
        moves += data->topb - i;  // If false, add the complement of 'i' to 'moves'.

    // Find the correct index on array 'a' where the element from array 'b' should be inserted.
    sortedindex = ft_find_correct_index_on_a(data, i);

    // Check if 'sortedindex' is less than half of the top index of array 'a'.
    if (sortedindex < data->topa / 2)
        moves += sortedindex;  // If true, add 'sortedindex' to 'moves'.
    else
        moves += data->topa - sortedindex;  // If false, add the complement of 'sortedindex' to 'moves'.

    return (moves);  // Return the total 'moves' required.
}

int ft_checkbestindex(t_data *data)
{
    int moves;
    int bestmoves;
    int bestindex;
    int i;

    i = data->topb;  // Initialize 'i' with the top index of array 'b'.

    bestmoves = ft_moves(data, i);  // Calculate the initial 'bestmoves' using 'i'.
    bestindex = data->topb;  // Set 'bestindex' to the top index of array 'b'.

    // Loop to iterate through the elements of array 'b' from top to bottom.
    while (i >= 0)
    {
        moves = ft_moves(data, i);  // Calculate 'moves' for the current 'i'.

        // Check if 'moves' is less than the current 'bestmoves'.
        if (moves < bestmoves)
        {
            bestmoves = moves;  // Update 'bestmoves' with the new, smaller 'moves'.
            bestindex = i;      // Update 'bestindex' with the current 'i'.
        }

        i--;  // Decrement 'i' to consider the next element in array 'b'.
    }

    return (bestindex);  // Return the index 'bestindex' with the fewest moves.
}

