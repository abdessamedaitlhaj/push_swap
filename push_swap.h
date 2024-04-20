/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:17:26 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/20 12:24:53 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	int		value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op
{
	char	*op;
	void	(*f)(t_stack *a, t_stack *b);
}				t_op;



t_stack	*parse_args(int argc, char **argv);



// utils
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, char *flag);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstclear(t_stack **stack);
t_stack	*ft_lstlast(t_stack *stack);
t_stack	*ft_lstnew(int value);
int		ft_lstsize(t_stack *stack);

int ft_isdigit(int c);
int	ft_isspace(int c);

int is_sorted(t_stack *stack);
int is_duplicate(t_stack *stack);
void error(void);
void free_args(char **args);

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **stack_a, t_stack **stack_b);

#endif