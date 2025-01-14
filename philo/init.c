/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:35:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/14 16:59:31 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_build(t_var *var)
{
	t_philo	**philo;
	t_fork 	**forks;
	int		i;

	i = 2;
	philo = (t_philo **)malloc(sizeof(t_philo *));
	forks = (t_fork **)malloc(sizeof(t_fork *) * (var->nb_philo));
	if (!forks || !philo)
		return (NULL);
	*philo = ft_new_philo(1, var);
	*forks = ft_new_fork(1, var);
	(*forks)->ph_lft = *philo;
	(*philo)->f_rgt = *forks;
	while (i <= var->nb_philo)
	{
		ft_lst_add_pnf(var, ft_new_philo(i, var), ft_new_fork(i, var));
		i++;
	}
	return (var);
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
	ft_build (var);
	return (var);
}
