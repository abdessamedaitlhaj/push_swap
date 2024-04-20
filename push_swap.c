/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:18:27 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/20 12:26:21 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	f(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	atexit(f);
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	print_stack(stack_a);
	ft_lstclear(&stack_a);
}