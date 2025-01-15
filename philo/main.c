/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:09:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 16:21:31 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*var;

	if (ft_is_arg_error(argc, argv) == 1)
		return (1);
	var = ft_init_var(argc, argv);
	ft_start_cycle(var);
	ft_manage_cycle(var);
	ft_wait(var);
	ft_end_cycle(var);
	return (0);
}
