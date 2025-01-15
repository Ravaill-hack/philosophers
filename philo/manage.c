/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 16:12:33 by lmatkows         ###   ########.fr       */
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
	/*
	faire des join sur les threads pour attendre qu'ils se terminent tous
	*/
	(void) var;
	return (0);
}

int	ft_end_cycle(t_var *var)
{
	free (var->philo);
	var->philo = NULL;
	free (var->mut_forks);
	var->mut_forks = NULL;
	free (var);
	var = NULL;
	return (0);
}
