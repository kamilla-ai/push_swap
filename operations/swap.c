/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:19:02 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/18 15:19:01 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacknode **a)
{
	t_stacknode	*tmp;

	if (!*a || !(*a)->next)
	{
		return ;
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stacknode **b)
{
	t_stacknode	*tmp;

	if (!*b || !(*b)->next)
	{
		return ;
	}
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*tmp;
	t_stacknode	*tmp1;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
	{
		return ;
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp1 = *b;
	*b = (*b)->next;
	tmp1->next = (*b)->next;
	(*b)->next = tmp1;
	write(1, "ss\n", 3);
}
