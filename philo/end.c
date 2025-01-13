/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 19:19:16 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_end(t_var *var)
{
	free (var->forks);
	var->forks = NULL;
	free (var->mutex_forks);
	var->mutex_forks = NULL;
	ft_lst_free (var->philo);
	free (var);
	var = NULL;
	return (0);
}

int	ft_lst_free(t_philo **philo)
{
	t_philo	*current;
	t_philo	*rgt;

	rgt = NULL;
	current = *philo;
	while (current)
	{
		if (current->rgt)
			rgt = current->rgt;
		if (current->lft)
			free (current->lft);
		if (current)
			free (current);
		current = rgt;
	}
	if (rgt)
		free (rgt);
	if (current)
		free (current);
	free (philo);
	return (0);
}
