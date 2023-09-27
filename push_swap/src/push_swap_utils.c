/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:27:05 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:23:57 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sign(char c, int *sign, int *i)
{
    // Check if the character 'c' is either '-' or '+'.
    if (c == '-' || c == '+')
    {
        // If 'c' is '-', set the value pointed to by 'sign' to -1 and increment the value pointed to by 'i' by 1.
        if (c == '-')
        {
            *sign = -1;  // Set 'sign' to -1 to indicate a negative sign.
            *i += 1;     // Increment 'i' by 1 to move to the next character.
        }
    }
}

int ft_atoi(t_data *data, char *str, char **args)
{
    int i;
    long res;
    int sign;

    sign = 1;  // Initialize the 'sign' variable to positive.
    res = 0;   // Initialize the 'res' variable to zero.
    i = 0;     // Initialize the 'i' variable to zero.

    // Check for and handle the sign symbol at the beginning of the string.
    ft_sign(str[i], &sign, &i);

    // Check if the first character is not a digit, and if so, free memory and exit.
    if (!ft_isdigit(str[i]))
        free_args(data, args);

    // Loop to convert the digits into an integer value.
    while (ft_isdigit(str[i]))
    {
        res = (res * 10) + str[i] - '0';  // Convert the character to an integer and add it to 'res'.
        i++;  // Move to the next character.

        // Check for overflow conditions and free memory and exit if met.
        if (((res > 2147483647) && (sign == 1)) || ((res > 2147483648) && (sign == -1)))
            free_args(data, args);
    }

    // Check if the loop ended because of a non-digit character or if 'i' exceeded 12 characters.
    if ((!ft_isdigit(str[i]) && str[i]) || i > 12)
        free_args(data, args);

    return (res * sign);  // Return the final integer value considering the sign.
}

int ft_lowesta(t_data *data)
{
    int i;
    int lowest;
    int lowestindex;

    i = 0;             // Initialize 'i' to zero to start iterating from the beginning of array 'a'.
    lowestindex = i;   // Initialize 'lowestindex' to 'i' to track the index of the lowest element.
    lowest = data->a[i];  // Initialize 'lowest' to the value of the first element in array 'a'.

    // Loop to iterate through elements of array 'a' from the beginning to the end.
    while (i <= data->topa)
    {
        // Check if the current element is lower than the current lowest.
        if (data->a[i] < lowest)
        {
            lowest = data->a[i];     // Update 'lowest' with the new lowest element.
            lowestindex = i;         // Update 'lowestindex' with the index of the new lowest element.
        }

        i++;  // Increment 'i' to move to the next element in array 'a'.
    }

    return (lowestindex);  // Return the index of the lowest element in array 'a'.
}

int get_values(t_data *data)
{
    // Calculate and store the best index in array 'b' to move to array 'a'.
    data->bestindex = ft_checkbestindex(data);

    // Store the value at the best index in array 'b'.
    data->bestvalue = data->b[data->bestindex];

    // Calculate and store the correct index in array 'a' for inserting the best value.
    data->correctadd = ft_find_correct_index_on_a(data, data->bestindex);

    // Store the value at the correct index in array 'a'.
    data->correctvalue = data->a[data->correctadd];

    // Return 0 to indicate successful completion.
    return (0);
}
