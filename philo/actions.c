/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 16:27:53 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_do_sth(void *var)
{
	t_var	*v;

	v = (t_var *)var;
	return (var);
}

void	ft_take_2_forks(t_var *var, int i_p)
{
	pthread_mutex_lock((var->philo[i_p]).f_lft);
	pthread_mutex_lock((var->philo[i_p]).f_rgt);
}

void	ft_free_2_forks(t_var *var, int i_p)
{
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
}
