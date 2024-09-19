/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:20:17 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/19 18:26:26 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
	{
		return (0);
	}
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

static void	rotate(char *line, t_stacknode **stacka, t_stacknode **stackb)
{
	if (ft_strcmp(line, "ra\n"))
		ra_bonus(stacka);
	else if (ft_strcmp(line, "rb\n"))
		rb_bonus(stackb);
	else if (ft_strcmp(line, "rr\n"))
		rr_bonus(stacka, stackb);
}

static void	rrotate(char *line, t_stacknode **stacka, t_stacknode **stackb)
{
	if (ft_strcmp(line, "rra\n"))
		rra_bonus(stacka);
	else if (ft_strcmp(line, "rrb\n"))
		rrb_bonus(stackb);
	else if (ft_strcmp(line, "rrr\n"))
		rrr_bonus(stacka, stackb);
}

static void	push_swap(char *line, t_stacknode **stacka, t_stacknode **stackb)
{
	if (ft_strcmp(line, "pa\n"))
		pa_bonus(stacka, stackb);
	else if (ft_strcmp(line, "pb\n"))
		pb_bonus(stacka, stackb);
	else if (ft_strcmp(line, "sa\n"))
		sa_bonus(stacka);
	else if (ft_strcmp(line, "sb\n"))
		sb_bonus(stackb);
	else if (ft_strcmp(line, "ss\n"))
		ss_bonus(stacka, stackb);
}

int	applyline(char *line, t_stacknode **stacka, t_stacknode **stackb)
{
	if (ft_strcmp(line, "ra\n") || ft_strcmp(line, "rb\n") || ft_strcmp(line,
			"rr\n"))
		rotate(line, stacka, stackb);
	else if (ft_strcmp(line, "rra\n") || ft_strcmp(line, "rrb\n")
		|| ft_strcmp(line, "rrr\n"))
		rrotate(line, stacka, stackb);
	else if (ft_strcmp(line, "pa\n") || ft_strcmp(line, "pb\n")
		|| ft_strcmp(line, "sa\n") || ft_strcmp(line, "sb\n") || ft_strcmp(line,
			"ss\n"))
		push_swap(line, stacka, stackb);
	else
		return (0);
	return (1);
}
