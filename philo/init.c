/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:35:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 19:05:09 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_build_philo(int nb_philo, t_var *var)
{
	t_philo	**philo;
	int		i;

	i = 1;
	philo = (t_philo **)malloc(sizeof(t_philo *));
	*philo = NULL;
	if (!philo)
		return (NULL);
	while (i <= nb_philo)
	{
		ft_lst_add_back(philo, ft_new_philo(i, var));
		i++;
	}
	return (philo);
}

int	*ft_build_forks(int nb_philo)
{
	int	*forks;
	int	i;

	forks = (int *)malloc(sizeof(int) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		forks[i] = 0;
		i++;
	}
	return (forks);
}

pthread_mutex_t	*ft_build_mutex(int nb_philo, t_var *var)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!mutex)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&(mutex[i]), NULL);
		i++;
	}
	return (mutex);
}

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->nb_philo = argv[1];
	var->t_2_die = argv[2];
	var->t_2_eat = argv[3];
	var->t_2_slp = argv[4];
	if (argc == 5)
		var->nb_eat_4_each = -1;
	else
		var->nb_eat_4_each = argv[5];
	var->forks = ft_build_forks(var->nb_philo);
	var->philo = ft_build_philo(var->nb_philo, var);
	var->mutex_forks = ft_build_mutex(var->nb_philo, var);
	return (var);
}
