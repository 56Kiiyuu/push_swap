/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:08:23 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/03 13:34:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	check_duplicates(t_stack_node *a)
{
	t_stack_node	*i;
	t_stack_node	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nbr == j->nbr)
				error_exit(&a);
			j = j->next;
		}
		i = i->next;
	}
}

static int	add_number(t_stack_node **a, char *str)
{
	long	nb;

	if (!is_number(str))
		return (0);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	add_node_back(a, (int)nb);
	return (1);
}

static void	parse_split(t_stack_node **a, char **split)
{
	int	j;

	if (!split || !split[0])
	{
		free_split(split);
		error_exit(a);
	}
	j = 0;
	while (split[j])
	{
		if (!add_number(a, split[j]))
		{
			free_split(split);
			error_exit(a);
		}
		j++;
	}
	free_split(split);
}

void	parse_args(t_stack_node **a, char **av)
{
	int		i;
	char	**split;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		parse_split(a, split);
		i++;
	}
	check_duplicates(*a);
}
