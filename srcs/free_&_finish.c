/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:59:10 by bat               #+#    #+#             */
/*   Updated: 2023/07/10 13:47:21 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_finish(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philo->sim_mutex);
	while (++i <= philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->forks[i]);
	}
	free(philo->threads);
	free(philo->forks);
	free(philo->sim_mutex);
	free(philo->sim_state);
	free(philo);
}