/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:14:43 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/18 21:10:11 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sortthree(t_stacknode **stacka)
{
	t_stacknode	*max;

	max = findmax(*stacka);
	if (*stacka == max)
	{
		ra(stacka);
	}
	else if ((*stacka)->next == max)
	{
		rra(stacka);
	}
	if ((*stacka)->nbr > (*stacka)->next->nbr)
	{
		sa(stacka);
	}
}

static t_stacknode	*findcheapest(t_stacknode *stack)
{
	t_stacknode	*min;

	min = stack;
	while (stack)
	{
		if (min->pushcost > stack->pushcost)
		{
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

static void	maketop(t_stacknode **a, t_stacknode **b, t_stacknode *cheapest)
{
	if (*b != cheapest && *a != cheapest->target)
	{
		if (!cheapest->secondhalf && !cheapest->target->secondhalf)
			while (*a != cheapest->target && *b != cheapest)
				rr(a, b);
		else if (cheapest->secondhalf && cheapest->target->secondhalf)
			while (*a != cheapest->target && *b != cheapest)
				rrr(a, b);
		else if (!cheapest->secondhalf && cheapest->target->secondhalf)
			while (*b != cheapest)
				rb(b);
		else if (cheapest->secondhalf && !cheapest->target->secondhalf)
			while (*a != cheapest->target)
				ra(a);
	}
}

static void	movenodes(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*cheapest;

	cheapest = findcheapest(*b);
	maketop(a, b, cheapest);
	if (*b == cheapest)
	{
		while (*a != cheapest->target)
		{
			if (!cheapest->target->secondhalf)
				ra(a);
			else
				rra(a);
		}
	}
	else if (*a == cheapest->target)
	{
		while (*b != cheapest)
		{
			if (!cheapest->secondhalf)
				rb(b);
			else
				rrb(b);
		}
	}
	pa(a, b);
}

void	sortmore(t_stacknode **a, t_stacknode **b)
{
	int			len;
	t_stacknode	*min;

	len = stacklen(*a);
	while (len-- > 3)
		pb(a, b);
	sortthree(a);
	while (*b)
	{
		setparameters(*a, *b);
		movenodes(a, b);
	}
	setparameters(*a, *b);
	min = findmin(*a);
	if (!min->secondhalf)
	{
		while (*a != min)
			ra(a);
	}
	if (min->secondhalf)
	{
		while (*a != min)
			rra(a);
	}
}
