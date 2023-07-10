/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:03:22 by bat               #+#    #+#             */
/*   Updated: 2023/07/10 14:41:46 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_positive_number(char *str)
{
    int i;

    i = -1;
    if (str[0] == '-')
        return (0);
    while (str[++i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int infos_check(int nb_args, char **infos)
{
    int i;

    i = 0;
    if (nb_args < 5 || nb_args > 6)
    {
        error_msg('A');
        return (0);
    }
    while (infos[++i])
    {
        if (!is_positive_number(infos[i]))
        {
            printf("Error, arguments must be positive\n");
            return (0);
        }
    }
    return (1);
}

int	error_msg(char flag)
{
	if (flag == 'M')
		printf("There is an error in the malloc of philo\n");
	else if (flag == 'A')
		printf("There is not enough arguments or\
		 they are not correctly formated\n");
	return (0);
}

void	msg(t_config *config, int status)
{
	static int	lol;

	if (status == EATS && lol < 1 && state(config))
		printf("%d %d is eating\n", get_time('n'), config->pos + 1);
	else if (status == SLEEPS && lol < 1 && state(config))
		printf("%d %d is sleeping\n", get_time('n'), config->pos + 1);
	else if (status == THINKS && lol < 1 && state(config))
		printf("%d %d is thinking\n", get_time('n'), config->pos + 1);
	else if (status == DIES && ++lol < 2)
		printf("%d %d died\n", get_time('n'), config->pos + 1);
	else if (status == FORKS && lol < 1 && state(config))
		printf("%d %d has taken a fork\n", get_time('n'), config->pos + 1);
}