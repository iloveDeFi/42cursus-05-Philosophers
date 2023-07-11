/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:01:38 by bat               #+#    #+#             */
/*   Updated: 2023/07/11 09:24:53 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    launch_simulation(t_philo **philo)
{
    int i;
    
    i = -1;
    create_philo(*philo);
    while(++i < nb_philo)
}

/* creates each thread of each individual philo */
void	create_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
		create_thread(philo, i);
}