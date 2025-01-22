/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:09:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/22 14:17:00 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*var;

	if (ft_is_arg_error(argc, argv) == 1)
		return (1);
	var = ft_init_var(argc, argv);
	//ft_print_data(* var);
	ft_join(var);
	ft_end_cycle(var);
	return (0);
}
