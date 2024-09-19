/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:59 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/19 18:24:14 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int	i;

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

static void	apply_and_check(t_stacknode **stacka, t_stacknode **stackb)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		if (!applyline(line, stacka, stackb))
		{
			free(line);
			write(1, "Error", 6);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ifsorted(*stacka))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
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
	apply_and_check(&stacka, &stackb);
	free_mem(&stacka, &stackb, split_av);
}
