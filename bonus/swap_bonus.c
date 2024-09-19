/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:19:02 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/19 15:16:46 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_stacknode **a)
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
}

void	sb_bonus(t_stacknode **b)
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
}

void	ss_bonus(t_stacknode **a, t_stacknode **b)
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
}
