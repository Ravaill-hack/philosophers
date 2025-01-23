/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/23 17:28:16 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int				n;
	long			h_last;
	long			h_2_die;
	int				nb_meals;
	pthread_t		thread;
	pthread_mutex_t	*f_rgt;
	pthread_mutex_t	*f_lft;
	struct s_var	*var;
}	t_philo;

typedef struct s_var
{
	long			t_start;
	int				dead;
	int				nb_philo;
	int				nb_finish;
	long			t_2_die;
	long			t_2_eat;
	long			t_2_slp;
	int				nb_eat_4_each;
	pthread_t		death_checker;
	pthread_mutex_t	m_m;
	pthread_mutex_t	m_d;
	pthread_mutex_t	m_f;
	pthread_mutex_t	*mut_forks;
	t_philo			*philo;
}	t_var;

/*
Fonctions d'initialisation
*/
t_var	*ft_init_var(int argc, char **argv);
void	ft_build(t_var *var);
void	ft_new_philo(t_var *var, t_philo *philo, int i);
/*
Fonctions pour gerer les erreurs
*/
int		ft_is_arg_error(int argc, char **argv);
int		ft_arg_number_error(int argc);
int		ft_type_error(char *str);
/*
Fonctions de demarrage et suivi
*/
void	*ft_check_end(void *v);
int		ft_join(t_var *var);
int		ft_end_cycle(t_var *var);
int		ft_philo_died(t_var *var, int i_p);
int		ft_some_1_died(t_var *var);
int		ft_philo_ate_enough(t_var *var, int i_p);
/*
Actions
*/
void	*ft_do_sth(void *var);
void	*ft_do_one(t_philo *philo);
void	*ft_eat_sleep_die(t_philo *philo);
int		ft_eat(t_var *var, int i_p);
void	ft_sleep(t_var *var, int i_p);
int		ft_take_2_forks(t_var *var, int i_p);
/*
Fonctions auxiliaires
*/
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(char *str);
long	ft_get_time_ms(void);
void	ft_put_message(int i_p, pthread_mutex_t *mut, char *str);
/*
Fonctions pour debugger
*/
void	ft_print_data(t_var	var);
void	ft_print_philo(t_var var, t_philo *philo, int i);

#endif
