/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:18:27 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/20 12:44:15 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker_bonus.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	get_instructions(t_stack **stack_a)
{
	t_stack	*stack_b;
	char	*line;

	(void)stack_a;

	stack_b = NULL;
	line = NULL;
	while (get_next_line(&line))
	{
		if (!ft_strncmp(line, "sa\n", 3))
			sa(stack_a);
		else if (!ft_strncmp(line, "sb\n", 3))
			sb(&stack_b);
		else if (!ft_strncmp(line, "ss\n", 3))
			ss(stack_a, &stack_b);
		else if (!ft_strncmp(line, "pa\n", 3))
			pa(stack_a, &stack_b);
		else if (!ft_strncmp(line, "pb\n", 3))
			pb(stack_a, &stack_b);
		else if (!ft_strncmp(line, "ra\n", 3))
			ra(stack_a);
		else if (!ft_strncmp(line, "rb\n", 3))
			rb(&stack_b);
		else if (!ft_strncmp(line, "rr\n", 3))
			rr(stack_a, &stack_b);
		else if (!ft_strncmp(line, "rra\n", 4))
			rra(stack_a);
		else if (!ft_strncmp(line, "rrb\n", 4))
			rrb(&stack_b);
		else if (!ft_strncmp(line, "rrr\n", 4))
			rrr(stack_a, &stack_b);
		else
			error();
		free(line);
	}
	if (is_sorted(*stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_b);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

// void	f(void)
// {
// 	system("leaks checker");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	get_instructions(&stack_a);
	ft_lstclear(&stack_a);
}