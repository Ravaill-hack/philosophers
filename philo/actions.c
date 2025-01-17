/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/17 15:23:47 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_do_sth(void *var)
{
	t_var	*v;

	v = (t_var *)var;
	return (var);
}

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (pthread_mutex_lock((var->philo[i_p]).f_lft) == 0)
		ft_put_message(i_p, var, "has taken a fork");
	else
		return (0);
	if (pthread_mutex_lock((var->philo[i_p]).f_rgt) == 0)
		ft_put_message(i_p, var, "has taken a fork");
	else
		return (0);
	return (1);
}

void	ft_free_2_forks(t_var *var, int i_p)
{
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
}

void	ft_is_thinking(t_var *var, int i_p)
{
	ft_put_message(i_p, var, "has taken a fork");
}
