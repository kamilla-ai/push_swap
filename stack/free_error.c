/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:06:46 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/19 19:01:59 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stacknode *stack)
{
	t_stacknode	*temp;

	if (stack == NULL)
	{
		return ;
	}
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_av(char **av)
{
	int	i;

	if (av == NULL)
	{
		return ;
	}
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ft_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

int	stacklen(t_stacknode *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	free_mem(t_stacknode **stacka, t_stacknode **stackb, char **split_av)
{
	free_stack(*stacka);
	free_stack(*stackb);
	free_av(split_av);
}
