#include "../includes/push_swap.h"

void	print_list(t_stack *stack)
{
	t_list *tmp;
	
	if (ft_stack_empty(stack))
	{
		printf("La stack est vide\n");
		return;
	}
	tmp = stack->start;
	while (tmp)
	{
		printf("[%d] \n", tmp->value);
		tmp = tmp->next;
	}
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}