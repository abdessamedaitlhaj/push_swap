/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:18:20 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/20 12:38:27 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsed(char **argv)
{
	int	i;
	char	**args;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0' || is_empty(argv[i]))
			return (0);
		args = ft_split(argv[i], ' ');
		if (!args)
			return (0);
		j = 0;
		while (args[j])
		{
			if (!is_number(args[j]))
				return (free_args(args), 0);
			j++;
		}
		free_args(args);
		i++;
	}
	return (1);
}

t_stack	*charge_stack(t_stack *stack_a, char **args)
{
	int		i;
	int		value;
	char	flag;

	i = 0;
	flag = 't';
	while (args[i])
	{
		value = ft_atoi(args[i], &flag);
		if (flag == 'f')
		{
			free_args(args);
			error();
		}
		ft_lstadd_back(&stack_a, ft_lstnew(value));
		i++;
	}
	return (stack_a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	char	**args;

	i = 1;
	stack_a = NULL;
	if (!parsed(argv))
		error();
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return (NULL);
		stack_a = charge_stack(stack_a, args);
		free_args(args);
		i++;
	}
	if (is_duplicate(stack_a))
	{
		ft_lstclear(&stack_a);
		error();
	}
	return (stack_a);
}