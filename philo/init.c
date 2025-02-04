/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:35:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 14:36:27 by lmatkows         ###   ########.fr       */
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
		i++;
	}
	i = 0;
	while (i < var->nb_philo)
	{
		ft_new_philo(var, &var->philo[i], i);
		i++;
	}
}

void	ft_new_philo(t_var *var, t_philo *philo, int nb)
{
	philo->n = nb + 1;
	philo->nb_meals = 0;
	philo->h_last = var->t_start;
	philo->h_2_die = philo->h_last + var->t_2_die;
	philo->var = var;
	if (var->nb_philo == 1)
	{
		philo->f_lft = &(var->mut_forks[0]);
		philo->f_rgt = NULL;
		pthread_create(&(philo->thread), NULL, &ft_do_sth, philo);
		return ;
	}
	if (nb == 0)
		philo->f_lft = &(var->mut_forks[0]);
	else
		philo->f_lft = &(var->mut_forks[nb]);
	if (nb == var->nb_philo - 1)
		philo->f_rgt = &(var->mut_forks[0]);
	else
		philo->f_rgt = &(var->mut_forks[nb + 1]);
	pthread_create(&(philo->thread), NULL, &ft_do_sth, philo);
}

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->nb_philo = (int)ft_atol(argv[1]);
	var->t_2_die = ft_atol(argv[2]);
	var->t_2_eat = ft_atol(argv[3]);
	var->t_2_slp = ft_atol(argv[4]);
	if (argc == 5)
		var->nb_eat_4_each = -1;
	else
		var->nb_eat_4_each = (int)ft_atol(argv[5]);
	var->t_start = ft_get_time_ms();
	var->dead = 0;
	var->end = 0;
	var->nb_finish = 0;
	pthread_create(&(var->death_checker), NULL, &ft_monitor, var);
	ft_build (var);
	pthread_mutex_init(&(var->m_e), NULL);
	pthread_mutex_init(&(var->m_m), NULL);
	pthread_mutex_init(&(var->m_d), NULL);
	pthread_mutex_init(&(var->m_f), NULL);
	return (var);
}
