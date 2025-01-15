/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:14:29 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 15:51:40 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &(s[i]), 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		c;

	nbr = (long int) n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + 48;
	write(fd, &c, 1);
}

long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * sign);
}

int	ft_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_put_message(int i_p, t_var *var, char *str)
{
	ft_putnbr_fd(ft_get_time_ms(), 1);
	write (1, " ", 1);
	ft_putnbr_fd(var->philo[i_p].n, 1);
	ft_putstr_fd(str, 1);
	write (1, "\n", 1);
}
