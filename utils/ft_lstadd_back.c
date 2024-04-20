/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:43:03 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/19 16:53:04 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
		ft_lstlast(*stack)->next = new;
	else
		*stack = new;
}
