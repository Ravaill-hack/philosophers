/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:35:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 14:43:47 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_build_philo(int nb_philo)
{
	t_philo	**philo;

	philo = (t_philo **)malloc(sizeof(t_philo *));
	*philo = NULL;
	if (!philo)
		return (NULL);
	return (philo);
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
	var->philo = ft_build_philo(var->nb_philo);
	if (argc == 5)
		var->nb_eat_4_each = -1;
	else
		var->nb_eat_4_each = argv[5];
	return (var);
}
