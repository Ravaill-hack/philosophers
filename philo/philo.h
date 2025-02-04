/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 16:58:41 by lmatkows         ###   ########.fr       */
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
	int				end;
	int				dead;
	int				nb_philo;
	int				nb_finish;
	long			t_2_die;
	long			t_2_eat;
	long			t_2_slp;
	int				nb_eat_4_each;
	pthread_t		death_checker;
	pthread_mutex_t	m_e;
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
Routines des threads
*/
void	*ft_monitor(void *v);
void	*ft_do_sth(void *var);
void	*ft_do_one(t_philo *philo);
/*
Fonctions de demarrage et suivi
*/
int		ft_join(t_var *var);
int		ft_end_cycle(t_var *var);
void	*ft_set_end(t_var *var);
/*
Fonctions de verification
*/
int		ft_check_philo_death(t_var *var, int i_p);
int		ft_check_philo_nb_meals(t_var *var, int i_p);
int		ft_check_philo(t_philo *philo);
int		ft_check_death(t_var *var);
int		ft_check_end(t_var *var);
/*
Actions
*/
int		ft_eat(t_var *var, int i_p);
int		ft_sleep(t_var *var, int i_p);
int		ft_take_2_forks(t_var *var, int i_p);
int		ft_lft_fork_first(t_var *var, int i_p);
int		ft_rgt_fork_first(t_var *var, int i_p);
int		ft_put_back_2_forks(t_var *var, int i_p);
/*
Fonctions auxiliaires
*/
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(char *str);
long	ft_get_time_ms(void);
void	ft_put_message(int i_p, pthread_mutex_t *mut, char *str);
int		ft_sleep_while_eating(long time, t_var *var);
int		ft_sleep_while_sleeping(long time, t_var *var, int i_p);
/*
Fonctions pour debugger
*/
void	ft_print_data(t_var	var);
void	ft_print_philo(t_var var, t_philo *philo, int i);

#endif
