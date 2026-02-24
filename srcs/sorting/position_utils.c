/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:08:11 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/24 13:35:56 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	if (!a || !*a)
		return ;
	min = find_min(*a);
	current_index(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	prep_for_push(t_stack_node **stack, t_stack_node *node, char name)
{
	current_index(*stack);
	while (*stack != node)
	{
		if (node->above_median)
		{
			if (name == 'a')
				ra(stack, true);
			else
				rb(stack, true);
		}
		else
		{
			if (name == 'a')
				rra(stack, true);
			else
				rrb(stack, true);
		}
	}
}
