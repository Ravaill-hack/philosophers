/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/14 16:50:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_fork
{
	int				n;
	int				is_used;
	pthread_mutex_t	mutex;
	struct s_philo	*ph_rgt;
	struct s_philo	*ph_lft;
	struct s_fork	*f_rgt;
	struct s_fork	*f_lft;
}	t_fork;

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
	t_fork			*f_rgt;
	t_fork			*f_lft;
}	t_philo;

typedef struct s_var
{
	int				nb_philo;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_slp;
	int				nb_eat_4_each;
	t_fork			**forks;
	t_philo			**philo;
}	t_var;

/*
Fonctions d'initialisation
*/
t_var			*ft_init_var(int argc, char **argv);
t_philo			**ft_build_philo(int nb_philo, t_var *var);
t_fork			**ft_build_forks(int nb_philo);
pthread_mutex_t	*ft_build_mutex(int nb_philo, t_var *var);
/*
Actions
*/
int				ft_do_sth(t_var *var);
/*
Fonctions auxiliaires - listes
*/
void			ft_lst_add_pnf(t_var *var, t_philo *new_p, t_fork *new_f);
t_philo			*ft_new_philo(int nb, t_var *var);
t_fork			*ft_new_fork(int nb, t_var *var);
t_fork			*ft_lst_last_fork(t_fork *fork);
t_philo			*ft_lst_last_philo(t_philo *philo);
/*
Fonctions pour terminer le programme
*/
int				ft_end(t_var *var);
int				ft_lst_free(t_philo **philo);

#endif
