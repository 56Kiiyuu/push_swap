/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:41:48 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/26 14:48:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest;
	long			best;

	cheapest = NULL;
	best = LONG_MAX;
	while (a)
	{
		if (a->push_cost < best)
		{
			best = a->push_cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}
