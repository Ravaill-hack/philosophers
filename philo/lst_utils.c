/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/14 17:01:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_new_philo(int nb, t_var *var)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->n = nb;
	philo->nb_meals = 0;
	philo->is_eating = 0;
	philo->h_end_last_meal = 0;
	philo->ph_lft = NULL;
	philo->ph_rgt = NULL;
	philo->f_lft = NULL;
	philo->f_rgt = NULL;
	pthread_create(&(philo->thread), NULL, ft_do_sth, var);
	return (philo);
}

t_fork	*ft_new_fork(int nb, t_var *var)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->n = nb;
	fork->f_lft = NULL;
	fork->f_rgt = NULL;
	fork->is_used = 0;
	pthread_mutex_init(&(fork->mutex), NULL);
	fork->ph_lft = NULL;
	fork->ph_rgt = NULL;
	fork->f_lft = NULL;
	fork->f_rgt = NULL;
	return (fork);
}

t_philo	*ft_lst_last_philo(t_philo *philo)
{
	t_philo	*current;

	current = philo;
	while (current->ph_rgt != NULL)
		current = current->ph_rgt;
	return (current);
}

t_fork	*ft_lst_last_fork(t_fork *fork)
{
	t_fork	*current;

	current = fork;
	while (current->f_rgt != NULL)
		current = current->f_rgt;
	return (current);
}

void	ft_lst_add_pnf(t_var *var, t_philo *new_p, t_fork *new_f)
{
	new_p->ph_lft = ft_lst_last_philo(*(var->philo));
	new_p->f_lft = ft_lst_last_fork(*(var->forks));
	new_f->ph_lft = new_p;
	new_f->f_lft = ft_lst_last_fork(*(var->forks));
	ft_lst_last_philo(*(var->philo))->ph_rgt = new_p;
	ft_lst_last_fork(*(var->forks))->ph_rgt = new_p;
	new_p->f_rgt = new_f;	
}

void	ft_chain_lst(t_var *var, t_philo *last_ph, t_fork *last_f)
{
	last
}
