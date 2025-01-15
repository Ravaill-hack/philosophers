/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:12 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 15:58:27 by lmatkows         ###   ########.fr       */
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
}	t_philo;

typedef struct s_var
{
	int 			t;
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
Fonctions pour gerer les erreurs
*/
int		ft_is_arg_error(int argc, char **argv);
int		ft_arg_number_error(int argc);
int		ft_type_error(char *str);
/*
Actions
*/
void	*ft_do_sth(void *var);
/*
Fonctions auxiliaires
*/
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(char *str);
int		ft_get_time_ms(void);
void	ft_put_message(int i_p, t_var *var, char *str);
/*
Fonctions pour terminer le programme
*/
int		ft_end(t_var *var);
/*
Fonctions pour debugger
*/
void	ft_print_data(t_var	var);

#endif
