/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:54:21 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/24 13:35:33 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node
		&& cheapest->above_median && cheapest->target_node->above_median)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node
		&& !cheapest->above_median && !cheapest->target_node->above_median)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node)
	{
		pb(b, a, true);
		return ;
	}
	if (!cheapest_node->target_node)
	{
		pb(b, a, true);
		return ;
	}
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_b;

	while (*b)
	{
		top_b = *b;
		init_nodes_b(*a, top_b);
		prep_for_push(a, top_b->target_node, 'a');
		prep_for_push(b, top_b, 'b');
		pa(a, b, true);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	if (!a || !*a)
		return ;
	len = stack_len(*a);
	while (len > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		len--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}
