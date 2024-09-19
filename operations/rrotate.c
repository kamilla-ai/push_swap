/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:18:59 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/15 14:14:27 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;
	t_stacknode	*tmp3;
	t_stacknode	*tmp4;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	tmp1 = *a;
	tmp2 = ft_lstlast(*a);
	*a = (*a)->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
	tmp3 = *b;
	tmp4 = ft_lstlast(*b);
	*b = (*b)->next;
	tmp4->next = tmp3;
	tmp3->next = NULL;
	write(1, "rr\n", 3);
}

void	rra(t_stacknode **a)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp1 = ft_lstlast(*a);
	tmp2 = ft_prelast(*a);
	tmp1->next = *a;
	*a = tmp1;
	tmp2->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stacknode **b)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp1 = ft_lstlast(*b);
	tmp2 = ft_prelast(*b);
	tmp1->next = *b;
	*b = tmp1;
	tmp2->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacknode **a, t_stacknode **b)
{
	t_stacknode	*tmp1;
	t_stacknode	*tmp2;
	t_stacknode	*tmp3;
	t_stacknode	*tmp4;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	tmp1 = ft_lstlast(*a);
	tmp2 = ft_prelast(*a);
	tmp1->next = *a;
	*a = tmp1;
	tmp2->next = NULL;
	tmp3 = ft_lstlast(*b);
	tmp4 = ft_prelast(*b);
	tmp3->next = *b;
	*b = tmp3;
	tmp4->next = NULL;
	write(1, "rrr\n", 4);
}
