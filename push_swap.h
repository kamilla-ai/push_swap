/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:19:11 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/19 17:07:05 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacknode
{
	int					nbr;
	struct s_stacknode	*next;
	int					index;
	struct s_stacknode	*target;
	int					pushcost;
	bool				secondhalf;
	bool				cheapest;
}						t_stacknode;

char					**ps_split(char const *s, char c);
long					ps_atoi(const char *str);
void					ft_error(void);
t_stacknode				*ft_lstlast(t_stacknode *lst);
t_stacknode				*ft_prelast(t_stacknode *lst);
t_stacknode				*findmax(t_stacknode *stack);
t_stacknode				*findmin(t_stacknode *stack);
int						stacklen(t_stacknode *stack);
void					sa(t_stacknode **a);
void					sb(t_stacknode **b);
void					ss(t_stacknode **a, t_stacknode **b);
void					pa(t_stacknode **a, t_stacknode **b);
void					pb(t_stacknode **a, t_stacknode **b);
void					ra(t_stacknode **a);
void					rb(t_stacknode **b);
void					rr(t_stacknode **a, t_stacknode **b);
void					rra(t_stacknode **a);
void					rrb(t_stacknode **b);
void					rrr(t_stacknode **a, t_stacknode **b);
void					sortthree(t_stacknode **stacka);
void					sortmore(t_stacknode **a, t_stacknode **b);
void					setparameters(t_stacknode *a, t_stacknode *b);
int						fillthestack(t_stacknode **stacka, char **av);
void					free_stack(t_stacknode *stack);
void					free_av(char **av);
void					free_mem(t_stacknode **stacka, t_stacknode **stackb,
							char **split_av);
#endif