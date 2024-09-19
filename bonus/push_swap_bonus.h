/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:48 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/19 17:07:21 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

typedef struct s_stacknode
{
	int					nbr;
	struct s_stacknode	*next;
}						t_stacknode;

char					**ps_split(char const *s, char c);
int						fillthestack(t_stacknode **stacka, char **av);
int						ps_atoi(const char *str);
void					sa_bonus(t_stacknode **a);
void					sb_bonus(t_stacknode **b);
void					ss_bonus(t_stacknode **a, t_stacknode **b);
void					pa_bonus(t_stacknode **a, t_stacknode **b);
void					pb_bonus(t_stacknode **a, t_stacknode **b);
void					ra_bonus(t_stacknode **a);
void					rb_bonus(t_stacknode **b);
void					rr_bonus(t_stacknode **a, t_stacknode **b);
void					rra_bonus(t_stacknode **a);
void					rrb_bonus(t_stacknode **b);
void					rrr_bonus(t_stacknode **a, t_stacknode **b);
int						applyline(char *operation, t_stacknode **stacka,
							t_stacknode **stackb);
t_stacknode				*ft_lstlast(t_stacknode *lst);
t_stacknode				*ft_prelast(t_stacknode *lst);
void					free_stack(t_stacknode *stack);
void					free_av(char **av);
void					free_mem(t_stacknode **stacka, t_stacknode **stackb,
							char **split_av);
void					ft_error(void);
#endif