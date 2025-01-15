/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 17:09:30 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_cycle(t_var *var)
{
	/*
	demarrer les actions : demander a un philosophe sur 2 de commencer a manger?
	*/
	(void) var;
	return (0);
}

int	ft_manage_cycle(t_var *var)
{
	/*
	surveiller ce qui se passe, afficher les messages d'etat correspondants
	*/
	(void) var;
	return (0);
}

int	ft_wait(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->nb_philo)
	{
		pthread_join(var->philo[i].thread, NULL);
		i++;
	}
	(void) var;
	return (0);
}

int	ft_end_cycle(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->nb_philo)
	{
		pthread_mutex_destroy(&(var->mut_forks[i]));
		i++;
	}
	free (var->mut_forks);
	var->mut_forks = NULL;
	free (var->philo);
	var->philo = NULL;
	free (var);
	var = NULL;
	return (0);
}
