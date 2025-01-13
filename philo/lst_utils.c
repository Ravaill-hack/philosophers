/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 19:05:14 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_new_philo(int nb, t_var *var)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->last_time_eating = 0;
	philo->lft = NULL;
	philo->rgt = NULL;
	pthread_create(&(philo->thread), NULL, ft_do_sth, var);
	return (philo);
}

t_philo	*ft_lst_last(t_philo *philo)
{
	t_philo	*current;

	current = philo;
	while (current->rgt != NULL)
		current = current->rgt;
	return (current);
}

void	ft_lst_add_back(t_philo **philo, t_philo *new)
{
	new->lft = ft_lst_last(*philo);
	(ft_lst_last(*philo))->rgt = new;
}
