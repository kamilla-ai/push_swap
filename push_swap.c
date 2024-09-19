/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:19:08 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/18 20:17:36 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ifsorted(t_stacknode *stack)
{
	if (!stack)
	{
		return (0);
	}
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

static int	is_only_spaces(const char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

static void	parsing(int ac, char **av)
{
	int			i;

	i = 1;
	if (ac == 1)
		exit(1);
	while (av[i])
	{
		if (av[i][0] == '\0' || is_only_spaces(av[i]))
			ft_error();
		i++;
	}
}

static int	sortthestack(t_stacknode **stacka, t_stacknode **stackb)
{
	if (!ifsorted(*stacka))
	{
		if (stacklen(*stacka) == 1)
			return (0);
		else if (stacklen(*stacka) == 2)
			sa(stacka);
		else if (stacklen(*stacka) == 3)
			sortthree(stacka);
		else
			sortmore(stacka, stackb);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacknode	*stacka;
	t_stacknode	*stackb;
	char		**split_av;

	stacka = NULL;
	stackb = NULL;
	split_av = NULL;
	parsing(ac, av);
	if (ac == 2)
	{
		split_av = ps_split(av[1], ' ');
		av = split_av;
	}
	if (!fillthestack(&stacka, av + 1))
	{
		free_mem(&stacka, &stackb, split_av);
		ft_error();
	}
	if (!sortthestack(&stacka, &stackb))
	{
		free_mem(&stacka, &stackb, split_av);
		return (0);
	}
	free_mem(&stacka, &stackb, split_av);
}
