/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setparameters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:14:47 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/18 15:34:43 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calculatecost(t_stacknode *a, t_stacknode *b)
{
	int	lena;
	int	lenb;

	lena = stacklen(a);
	lenb = stacklen(b);
	while (b)
	{
		if (b->secondhalf == false)
		{
			if (b->target->secondhalf == false)
				b->pushcost = b->index + b->target->index + 1;
			else
				b->pushcost = b->index + (lena - b->target->index) + 1;
		}
		else
		{
			if (b->target->secondhalf == false)
				b->pushcost = (lenb - b->index) + b->target->index + 1;
			else
				b->pushcost = (lenb - b->index) + (lena - b->target->index) + 1;
		}
		b = b->next;
	}
	return ;
}

static void	findtarget(t_stacknode *a, t_stacknode *b)
{
	t_stacknode	*iter;
	t_stacknode	*target;
	int			nextmax;

	target = NULL;
	iter = NULL;
	while (b)
	{
		iter = a;
		nextmax = 2147483647;
		while (iter)
		{
			if (iter->nbr > b->nbr && iter->nbr <= nextmax)
			{
				target = iter;
				nextmax = target->nbr;
			}
			iter = iter->next;
		}
		if (nextmax == 2147483647)
			b->target = findmin(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	setindexes(t_stacknode *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
	{
		return ;
	}
	median = stacklen(stack) / 2 + 1;
	while (stack != NULL)
	{
		stack->index = i;
		if (i < median)
		{
			stack->secondhalf = false;
		}
		else
		{
			stack->secondhalf = true;
		}
		i++;
		stack = stack->next;
	}
	return ;
}

void	setparameters(t_stacknode *a, t_stacknode *b)
{
	findtarget(a, b);
	setindexes(a);
	setindexes(b);
	calculatecost(a, b);
}
