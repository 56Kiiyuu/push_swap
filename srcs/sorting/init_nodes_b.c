/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:46:47 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/26 15:49:43 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_stack_node	*find_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target;
	long			best_match;

	current_index(a);
	current_index(b);
	best_match = LONG_MAX;
	cur_a = a;
	target = NULL;
	while (cur_a)
	{
		if (cur_a->nbr > b->nbr && cur_a->nbr < best_match)
		{
			best_match = cur_a->nbr;
			target = cur_a;
		}
		cur_a = cur_a->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		b->target_node = find_target_b(a, b);
		b = b->next;
	}
	current_index(a);
	current_index(b);
}
