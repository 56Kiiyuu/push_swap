/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:20 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/26 15:33:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->nbr;
	mid = (*a)->next->nbr;
	bot = (*a)->next->next->nbr;
	if (top > mid && mid < bot && top < bot)
		sa(a, true);
	else if (top > mid && mid > bot)
	{
		sa(a, true);
		rra(a, true);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, true);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, true);
}
