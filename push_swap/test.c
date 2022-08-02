#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	stack
{
	int			capacity;
	int			size;
	int			*list;
}stack;

void	put_char(char c)
{
	write(1, &c, 1);
}

void	putstr(char const *s)
{
	while (*s)
		put_char(*(s++));
}

void		pop(stack *stck)
{
	if (stck->size != 0)
		stck->size--;
}

void		push(stack *stck, int element)
{
	if (stck->size == stck->capacity)
		exit(0);
	stck->list[stck->size++] = element;
}

int			top(stack *stck)
{
	if (stck->size == 0)
		exit(0);
	return (stck->list[stck->size - 1]);
}

//swap a or b
void	swap_sa_sb(int *my_stack, int size)
{
	int	temp;

	temp = my_stack[size - 2];
	my_stack[size - 2] = my_stack[size - 1];
	my_stack[size - 1] = temp;
}

//rotate a or b
void	rotate_ra_rb(int *my_stack, int size)
{
	int	i;
	int	first_element;
	int	tmp;
	int	tmp1;

	i = 0;
	first_element = my_stack[size - 1];
	tmp = my_stack[i];
	my_stack[i] = first_element;
	while (++i < size)
	{
		tmp1 = my_stack[i];
		my_stack[i] = tmp;
		tmp = tmp1;
	}
}

//reverse rotate a or b
void	rotate_rra_rrb(int *my_stack, int size)
{
	int	i;
	int	last_element;
	int	tmp1;
	int	tmp;

	i = size - 1;
	last_element = my_stack[0];
	tmp = my_stack[i];
	my_stack[i] = last_element;
	while (--i >= 0)
	{
		tmp1 = my_stack[i];
		my_stack[i] = tmp;
		tmp = tmp1;
	}
}

//push pa
void	pa(stack *stck_a, stack *stck_b)
{
	push(stck_a, top(stck_b));
	pop(stck_b);
}

//push pb
void	pb(stack *stck_a, stack *stck_b)
{
	push(stck_b, top(stck_a));
	pop(stck_a);
}

//swap sa and sb at the same time
void	swap_ss(int *stck_a, int a_size, int *stck_b, int b_size)
{
	swap_sa_sb(stck_a, a_size);
	swap_sa_sb(stck_b, b_size);
}

//rotate a and b at the same time
void	rr(int *a, int a_size, int *b, int b_size)
{
	rotate_ra_rb(a, a_size);
	rotate_ra_rb(b, b_size);
}

//reverse rotate a and b at the same time
void	rrr(int *a, int a_size, int *b, int b_size)
{
	rotate_rra_rrb(a, a_size);
	rotate_rra_rrb(b, b_size);
}

//check if stack is sorted
 int		is_not_sorted(stack *stck)
{
	int	i;

	i = stck->size - 1;
	while (i >= 0 && (i - 1) >= 0)
	{
		if (stck->list[i] > stck->list[i - 1])
			return (i);
		i--;
	}
	return (0);
}

//create stack.
stack		*create_stack(int size)
{
	stack	*stck;

	stck = (stack *)malloc(sizeof(stack) * size);
	if (stck)
	{
		stck->list = (int *)malloc(sizeof(int) * size);
		stck->size = 0;
		stck->capacity = size;
	}
	return (stck);
}

//sort stack.
void	push_swap(stack *a, stack *b)
{
	int		srt;

	srt = is_not_sorted(a);
	if (srt)
	{
		if (a->list[srt] == top(a) && a->list[srt] > a->list[0])
		{
			rotate_ra_rb(a->list, a->size);
			putstr("ra\n");
		}
		else if (a->list[srt] == top(a) && a->list[srt] > a->list[srt - 1])
		{
			swap_sa_sb(a->list, a->size);
			putstr("sa\n");
		}
		else if (a->list[srt] > a->list[srt - 1])
		{
			putstr("pb\n");
			pb(a, b);
		}
		push_swap(a, b);
	}
	else if (b->size > 0)
	{
		if (top(a) < top(b))
		{
			pa(a, b);
			putstr("pa\n");
		}
		else if ((top(a) > top(b)) && b->size != 0)
		{
			pa(a, b);
			putstr("pa\n");
		}
		push_swap(a, b);
	}
}

//duplicate int array.
int * intdup(int const * src, size_t len)
{
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

int		main(int ac, char **av)
{
	int		num;
	int     stck[] = {23,-80,-10};
	stack	*a;
	stack	*b;

	num = 3;
	a = create_stack(num);
	b = create_stack(num);
	a->list = intdup(stck, num);
	a->size = num;
	push_swap(a, b);
	//printf("\n");
	int i = num - 1;
	while (i >= 0)
	{
		printf("%d\n", a->list[i]);
		i--;
	}
	return (0);
}