/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:44:51 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/18 12:00:51 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		cur_b = b;
		target = NULL;
		while (cur_b)
		{
			if (cur_b->nbr < a->nbr && cur_b->nbr > best_match)
			{
				best_match = cur_b->nbr;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (!target)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static int	get_cost(int len, int index, bool above)
{
	if (above)
		return (index);
	return (len - index);
}

static int	calc_push_cost(int cost_a, int cost_b, bool same_side)
{
	if (same_side)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	return (cost_a + cost_b);
}

static void	set_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		cost_a = get_cost(len_a, a->index, a->above_median);
		if (!a->target_node)
			a->push_cost = cost_a;
		else
		{
			cost_b = get_cost(len_b, a->target_node->index,
					a->target_node->above_median);
			a->push_cost = calc_push_cost(cost_a, cost_b,
					a->above_median == a->target_node->above_median);
		}
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;

	if (!a)
		return ;
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	tmp = a;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	cheapest = get_cheapest(a);
	if (cheapest)
		cheapest->cheapest = true;
}
