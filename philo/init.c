/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:35:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 15:50:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_build(t_var *var)
{
	int		i;

	i = 0;
	var->philo = malloc(var->nb_philo * sizeof(t_philo));
	var->mut_forks = malloc(var->nb_philo * sizeof(pthread_mutex_t));
	if (!(var->philo) || !(var->mut_forks))
		return ;
	while (i < var->nb_philo)
	{
		pthread_mutex_init(&(var->mut_forks[i]), NULL);
		var->philo[i] = ft_new_philo(i + 1, var);
		i++;
	}
	if (var->nb_philo == 1)
	{
		var->philo[0].ph_lft = NULL;
		var->philo[0].ph_rgt = NULL;
		var->philo[0].f_rgt = NULL;
	}
	else
	{
	var->philo[var->nb_philo - 1].ph_rgt = &(var->philo[0]);
	var->philo[var->nb_philo - 1].f_rgt = &(var->mut_forks[0]);
	}
}

t_philo	ft_new_philo(int nb, t_var *var)
{
	t_philo	philo;

	if(nb == 1)
	{
		philo.ph_lft = &(var->philo[var->nb_philo - 1]);
		philo.f_lft = &(var->mut_forks[0]);
	}
	else
	{
		philo.ph_lft = &(var->philo[nb - 2]);
		philo.f_lft = &(var->mut_forks[nb - 1]);
	}	
	philo.n = nb;
	philo.nb_meals = 0;
	philo.h_2_die = 0;
	philo.is_eating = 0;
	philo.h_end_last_meal = 0;
	philo.ph_rgt = &(var->philo[nb]);
	philo.f_rgt = &(var->mut_forks[nb]);
	pthread_create(&(philo.thread), NULL, ft_do_sth, var);
	return (philo);
}

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->t = ft_get_time_ms();
	var->nb_philo = (int)ft_atol(argv[1]);
	var->t_2_die = (int)ft_atol(argv[2]);
	var->t_2_eat = (int)ft_atol(argv[3]);
	var->t_2_slp = (int)ft_atol(argv[4]);
	if (argc == 5)
		var->nb_eat_4_each = -1;
	else
		var->nb_eat_4_each = (int)ft_atol(argv[5]);
	ft_build (var);
	return (var);
}
