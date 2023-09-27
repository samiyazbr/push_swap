/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:36:39 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:19:40 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(t_data *data)
{
    free(data->indexarray);  // Free dynamically allocated memory for 'indexarray'.
    free(data->a);           // Free dynamically allocated memory for 'a'.
    free(data->b);           // Free dynamically allocated memory for 'b'.

    write(2, "Error\n", 6);  // Write the error message "Error\n" to standard error (file descriptor 2).

    exit(0);                 // Terminate the program with an exit status of 0 (indicating success).
}

void free_args(t_data *data, char **args)
{
    int i;

    i = 0;  // Initialize an index variable 'i' to zero.

    free(data->indexarray);  // Free dynamically allocated memory for 'indexarray'.
    free(data->a);           // Free dynamically allocated memory for 'a'.
    free(data->b);           // Free dynamically allocated memory for 'b'.

    // Loop to free dynamically allocated memory for each element in the 'args' array.
    while (args[i])
    {
        free(args[i]);
        i++;
    }

    free(args);  // Free dynamically allocated memory for the 'args' array.

    write(2, "Error\n", 6);  // Write the error message "Error\n" to standard error (file descriptor 2).

    exit(0);  // Terminate the program with an exit status of 0 (indicating success).
}

void ft_free(t_data *data)
{
    // Free dynamically allocated memory for 'a'.
    free(data->a);

    // Set the pointer 'a' to NULL to avoid using the freed memory.
    data->a = NULL;

    // Free dynamically allocated memory for 'b'.
    free(data->b);

    // Set the pointer 'b' to NULL to avoid using the freed memory.
    data->b = NULL;

    // Free dynamically allocated memory for 'indexarray'.
    free(data->indexarray);

    // Set the pointer 'indexarray' to NULL to avoid using the freed memory.
    data->indexarray = NULL;
}
