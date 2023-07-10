/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:01:40 by bat               #+#    #+#             */
/*   Updated: 2023/07/10 15:49:00 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* returns true if the state of the sim is to continue */
int	state(t_config *config)
{
	if (!config->life)
		return (0);
	if ((config->t_die + config->last_bite) < get_time('n'))
	{
		state_update(config, 'L');
		return (0);
	}
	pthread_mutex_lock(config->sim_mutex);
	if (config->sim_state[0] == 0)
	{
		pthread_mutex_unlock(config->sim_mutex);
		config->life = 0;
		return (0);
	}
	pthread_mutex_unlock(config->sim_mutex);
	return (1);
}

/* updates the sim_state variable based on the flag
	if flag == 'L', put sim_state[0] == 0
	if flag == 'E', increases sim_state[1]++
	and check if the philos have all eaten */

void	state_update(t_config *config, char flag)
{
	if (flag == 'L')
	{
		pthread_mutex_lock(&config->sim_mutex[0]);
		config->sim_state[0] = 0;
		pthread_mutex_unlock(&config->sim_mutex[0]);
		config->life = 0;
		msg(config, DIES);
		return ;
	}
	if (flag == 'E')
	{
		pthread_mutex_lock(&config->sim_mutex[1]);
		config->sim_state[1] += 1;
		if (config->sim_state[1] == config->nb_philo)
		{
			pthread_mutex_lock(&config->sim_mutex[0]);
			config->sim_state[0] = 0;
			pthread_mutex_unlock(&config->sim_mutex[0]);
			config->life = 0;
		}
		pthread_mutex_unlock(&config->sim_mutex[1]);
	}
	return ;
}