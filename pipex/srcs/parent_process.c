/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:26 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 20:17:21 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_process(t_pipex *p, int pid)
{
	close(p->pipe[P_WRITE]);
	if (dup2(p->pipe[P_READ], STDIN_FILENO) == -1)
		perror("dup2(stdin)");
	close(p->pipe[P_READ]);
}
