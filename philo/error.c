/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:51:51 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 10:28:41 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_arg_number_error(int argc)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Error, wrong number of arguments\n", 2);
		return (1);
	}
	return (0);
}

int	ft_type_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("Error, wrong syntax or negative number\n", 2);
			return (1);
		}
		i++;
	}
	if (ft_atol(str) > INT_MAX)
	{
		ft_putstr_fd("Error, number bigger than INTMAX\n", 2);
		return (1);
	}
	return (0);
}

int	ft_is_arg_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (ft_arg_number_error(argc) == 1)
	{
		ft_putstr_fd("\nThe arguments should be set as following :\n\n", 1);
		ft_putstr_fd("./philo nb_philos t_2_die t_2_eat t_2_slp\n\n", 1);
		ft_putstr_fd("a 5th arg can be added : nb_meals_for_each_phil\n\n", 1);
		return (1);
	}
	while (i < argc)
	{
		if (ft_type_error(argv[i]) == 1)
		{
			ft_putstr_fd("\nThe arguments should be set as following :\n", 1);
			ft_putstr_fd("./philo nb_philos t_2_die t_2_eat t_2_slp\n", 1);
			ft_putstr_fd("a 5th arg can be added : nb_meals_4_each_phil\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_print_data(t_var	var)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(var.m_m));
	printf("var : %p\n", &var);
	printf("nb philo : %d %p\n", var.nb_philo, &var.nb_philo);
	printf("time die : %ldms %p\n", var.t_2_die, &var.t_2_die);
	printf("t0 : %ldms %p\n", var.t_start, &var.t_start);
	printf("time eat : %ldms %p\n", var.t_2_eat, &var.t_2_eat);
	printf("time sleep : %ldms %p\n", var.t_2_slp, &var.t_2_slp);
	printf("meals : %d %p\n\n", var.nb_eat_4_each, &var.nb_eat_4_each);
	while (i < var.nb_philo)
	{
		ft_print_philo(var, &(var.philo[i]), i);
		i++;
	}
	pthread_mutex_unlock(&(var.m_m));
}

void	ft_print_philo(t_var var, t_philo *philo, int i)
{
	printf("adr fork : %p\n\n", &var.mut_forks[i]);
	printf("lft fork : %p\n", philo->f_lft);
	printf("adr philo : %p\n", philo);
	printf("id : %d %p\n", philo->n, &philo->n);
	printf("last meal : %ld %p\n", philo->h_last, &philo->h_last);
	printf("hour 2 die : %ld %p\n", philo->h_2_die, &philo->h_2_die);
	printf("nb meals : %d %p\n", philo->nb_meals, &philo->nb_meals);
	printf("rgt fork : %p\n\n", philo->f_rgt);
}
