/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:15:10 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/18 15:18:33 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacknode	*findmin(t_stacknode *stack)
{
	t_stacknode	*min;

	min = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (min->nbr > stack->nbr)
		{
			min = stack;
		}
	}
	return (min);
}

t_stacknode	*findmax(t_stacknode *stack)
{
	t_stacknode	*max;

	max = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (max->nbr < stack->nbr)
		{
			max = stack;
		}
	}
	return (max);
}

t_stacknode	*ft_lstlast(t_stacknode *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stacknode	*ft_prelast(t_stacknode *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
