#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	*indexarray;
	int	topa;
	int	topb;
	int	bestindex;
	int	bestvalue;
	int	correctadd;
	int	correctvalue;
}	t_data;

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	double_check_arg(t_data *data, char *str);

#endif