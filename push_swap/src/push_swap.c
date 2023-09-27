/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:19:26 by szubair           #+#    #+#             */
/*   Updated: 2022/11/04 13:22:00 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void double_check_arg(t_data *data, char *str)
{
    int i;
    char **args;

    // Split the input string 'str' into an array of strings using space (' ') as a delimiter.
    args = ft_split(str, ' ');

    // Free the original 'str' as it's no longer needed.
    free(str);

    // Initialize the 'data' structure using the parsed 'args' array.
    initialize(data, args);

    i = 0;

    // Free each individual string in the 'args' array.
    while (args[i])
    {
        free(args[i]);
        i++;
    }

    // Free the 'args' array itself.
    free(args);
}

void initialize(t_data *data, char **av)
{
    int i;
    int j;

    i = 0;

    // Count the number of elements in the 'av' array by iterating through it.
    while (av[i])
        i++;

    // Allocate memory for the 'indexarray', 'a', and 'b' arrays based on the count of elements in 'av'.
    data->indexarray = (int *)malloc(sizeof(int) * i);
    data->a = (int *)malloc(sizeof(int) * i);
    data->b = (int *)malloc(sizeof(int) * i);

    // Check if any of the memory allocations failed.
    if (!data->indexarray || !data->a || !data->b)
        error(data);

    j = 0;
    i--;

    // Fill the 'indexarray' and 'a' arrays by iterating through 'av' in reverse order.
    while (i >= 0)
    {
        data->indexarray[j] = ft_atoi(data, av[i], av);
        data->a[j++] = ft_atoi(data, av[i--], av);
    }

    // Set 'topa' to the last index of the 'a' array.
    data->topa = j - 1;

    // Initialize 'topb' to -1 to indicate an empty 'b' array.
    data->topb = -1;
}

int main(int argc, char **argv)
{
    t_data data;     // Declare a 't_data' structure variable named 'data'.
    int i;           // Declare an integer variable 'i'.
    char *str;       // Declare a character pointer variable 'str' for string concatenation.
    int flag;        // Declare an integer variable 'flag' for tracking concatenation.

    str = "";        // Initialize 'str' with an empty string.
    
    // Check if the program is called with at least one command-line argument.
    if (argc == 1)
        exit(EXIT_SUCCESS);  // Exit the program with success code if no arguments are provided.

    i = 1;            // Initialize 'i' to 1 to start iterating through the command-line arguments.
    flag = 0;         // Initialize 'flag' to 0 as there is no concatenation yet.

    // Iterate through the 'argv' array to concatenate command-line arguments into 'str'.
    while (argv[i])
    {
        str = ft_strjoin(str, argv[i], flag);  // Concatenate the current argument to 'str'.
        flag = 1;                              // Set 'flag' to 1 to indicate concatenation.
        i++;                                   // Move to the next command-line argument.
    }

    // Perform checks on the concatenated 'str' and initialize the 'data' structure accordingly.
    double_check_arg(&data, str);

    // Perform further checks and sorting operations using the 'data' structure.
    ft_check(&data);

    return (0);  // Return 0 to indicate successful program execution.
}