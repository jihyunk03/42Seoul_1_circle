/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:42:44 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 13:23:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TRUE		1
# define FALSE		0

# define AVAILABLE	0		// default value == 0 (ft_calloc)
# define USING		1

# define CONTINUE	1
# define END		0

enum	e_errno
{
	SUCCESS,
	ALLOC_FAIL,
	ARG_ERR,
	MUTEX_ERR,
	PHILO_ERR
};

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"

#endif
