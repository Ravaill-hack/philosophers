/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/20 14:35:16 by lmatkows         ###   ########.fr       */
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
	int				h_end_last_meal;
	int				is_eating;
	int				h_2_die;
	int				nb_meals;
	pthread_t		thread;
	struct s_philo	*ph_rgt;
	struct s_philo	*ph_lft;
	pthread_mutex_t	*f_rgt;
	pthread_mutex_t	*f_lft;
	struct	s_var	*var;
}	t_philo;

typedef struct s_var
{
	long 			t_start;
	int				nb_philo;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_slp;
	int				nb_eat_4_each;
	int				some1_died;
	pthread_mutex_t	*mut_forks;
	pthread_mutex_t	mut_var;
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
int		ft_manage_cycle(t_var *var);
int		ft_join(t_var *var);
int		ft_end_cycle(t_var *var);
/*
Actions
*/
void	*ft_do_sth(void *var);
void	ft_eat(t_var *var, int i_p);
void	ft_sleep(t_var *var, int i_p);
void	ft_think(t_var *var, int i_p);
int		ft_take_2_forks(t_var *var, int i_p);
void	ft_free_2_forks(t_var *var, int i_p);
/*
Fonctions auxiliaires
*/
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(char *str);
long	ft_get_time_ms(void);
void	ft_put_message(int i_p, t_var *var, char *str);
/*
Fonctions pour debugger
*/
void	ft_print_data(t_var	var);

#endif
