/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:23:52 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/19 22:15:20 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_checker_bonus.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}
