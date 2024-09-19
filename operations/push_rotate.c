/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:18:55 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/18 15:21:38 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*tmp;

	if (!(*b))
	{
		return ;
	}
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*tmp;

	if (!(*a))
	{
		return ;
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_stacknode **a)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp1 = *a;
	tmp2 = ft_lstlast(*a);
	*a = (*a)->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stacknode **b)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp1 = *b;
	tmp2 = ft_lstlast(*b);
	*b = (*b)->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
	write(1, "rb\n", 3);
}
