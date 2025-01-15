/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 12:55:48 by lmatkows         ###   ########.fr       */
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
	int				n;
	int				h_end_last_meal;
	int				is_eating;
	int				h_2_die;
	int				nb_meals;
	pthread_t		thread;
	struct s_philo	*ph_rgt;
	struct s_philo	*ph_lft;
	pthread_mutex_t	*f_rgt;
	pthread_mutex_t	*f_lft;
}	t_philo;

typedef struct s_var
{
	int				nb_philo;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_slp;
	int				nb_eat_4_each;
	pthread_mutex_t	*mut_forks;
	t_philo			*philo;
}	t_var;

/*
Fonctions d'initialisation
*/
t_var	*ft_init_var(int argc, char **argv);
void	ft_build(t_var *var);
t_philo	ft_new_philo(int nb, t_var *var);
/*
Actions
*/
int		ft_do_sth(t_var *var);
/*
Fonctions auxiliaires - listes
*/

/*
Fonctions pour terminer le programme
*/
int		ft_end(t_var *var);

#endif
