/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:45 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/19 22:15:20 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_checker_bonus.h"

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}
