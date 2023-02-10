/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:47 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/10 13:41:19 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a_stack)
{
	int	tmp;

	if (a_stack->size < 2)
		return ;
	tmp = a_stack->head->idx;
	a_stack->head->idx = a_stack->head->next->idx;
	a_stack->head->next->idx = tmp;
}

void	sb(t_stack *b_stack)
{
	int	tmp;

	if (b_stack->size < 2)
		return ;
	tmp = b_stack->head->idx;
	b_stack->head->idx = b_stack->head->next->idx;
	b_stack->head->next->idx = tmp;
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}
