/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:53:52 by bat               #+#    #+#             */
/*   Updated: 2023/07/10 13:24:05 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (0);
    if (!infos_check(ac, av))
        return (0);
    initialize(philo, av);
    lauch_simulation(&philo);
    terminate(philo);
    return (0);
}

int	main(int ac, char **av)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	if (!infos_check(av, ac))
		return (0);
	initialize(philo, av);
	launch_sim(&philo);
	terminate(philo);
	return (0);
}

/* initializes the philo struct based on the given infos */
void	initialize(t_philo *philo, char **settings)
{
	int	i;

	i = 0;
	philo->nb_philo = ft_atoi(settings[++i]);
	if (philo->nb_philo < 1)
		return ;
	philo->time_die = ft_atoi(settings[++i]);
	philo->time_eat = ft_atoi(settings[++i]);
	philo->time_sleep = ft_atoi(settings[++i]);
	if (settings[++i])
		philo->nb_time_eat = ft_atoi(settings[i]);
	else
		philo->nb_time_eat = -1;
	philo->threads = malloc(sizeof(pthread_t) * philo->nb_philo);
	if (!philo->threads)
		return ;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->forks)
		return ;
	initialize_next(philo);
}

void	initialize_next(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			return ;
	}
	philo->sim_mutex = malloc(sizeof(pthread_mutex_t));
	if (!philo->sim_mutex)
		return ;
	if (pthread_mutex_init(philo->sim_mutex, NULL) != 0)
		return ;
	philo->sim_state = malloc(sizeof(int) * 2);
	if (!philo->sim_state)
		return ;
	philo->sim_state[0] = 1;
	philo->sim_state[1] = 0;
	get_time('i');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}