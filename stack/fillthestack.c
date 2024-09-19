/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillthestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:18:50 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/18 20:36:58 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	checkdups(t_stacknode *stacka, int nbr)
{
	t_stacknode	*temp;

	temp = stacka;
	while (temp)
	{
		if (temp->nbr == nbr)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

static void	putnode(t_stacknode **stacka, int nbr)
{
	t_stacknode	*node;
	t_stacknode	*lastnode;

	node = malloc(sizeof(t_stacknode));
	if (!node)
	{
		return ;
	}
	node->nbr = nbr;
	node->next = NULL;
	if (*stacka == NULL)
	{
		*stacka = node;
	}
	else
	{
		lastnode = ft_lstlast(*stacka);
		lastnode->next = node;
	}
}

int	fillthestack(t_stacknode **stacka, char **av)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (av[i])
	{
		nbr = ps_atoi(av[i]);
		if (nbr == 2147483649 || nbr == -2147483649)
		{
			return (0);
		}
		if (!checkdups(*stacka, nbr))
		{
			return (0);
		}
		putnode(stacka, nbr);
		i++;
	}
	return (1);
}
