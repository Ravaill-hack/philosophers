/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 14:33:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				n_philo;
	struct s_philo	*rgt;
	struct s_philo	*lft;
}	t_philo;

typedef struct s_var
{
	int	nb_philo;
	int	t_2_die;
	int	t_2_eat;
	int	t_2_slp;
	int	nb_eat_4_each;
	t_philo **philo;
}	t_var;

#endif
