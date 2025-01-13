/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/13 19:04:50 by lmatkows         ###   ########.fr       */
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
	int				last_time_eating;
	pthread_t		thread;
	struct s_philo	*rgt;
	struct s_philo	*lft;
}	t_philo;

typedef struct s_var
{
	int				nb_philo;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_slp;
	int				nb_eat_4_each;
	int				*forks;
	pthread_mutex_t	*mutex_forks;
	t_philo			**philo;
}	t_var;

/*
Fonctions d'initialisation
*/
t_var			*ft_init_var(int argc, char **argv);
t_philo			**ft_build_philo(int nb_philo, t_var *var);
int				*ft_build_forks(int nb_philo);
pthread_mutex_t	*ft_build_mutex(int nb_philo, t_var *var);
/*
Actions
*/
int				ft_do_sth(t_var *var);
/*
Fonctions auxiliaires - listes
*/
t_philo			*ft_new_philo(int nb, t_var *var);
void			ft_lst_add_back(t_philo **philo, t_philo *new);
t_philo			*ft_lst_last(t_philo *philo);

#endif
