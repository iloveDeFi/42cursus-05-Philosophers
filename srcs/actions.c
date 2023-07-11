/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:03:10 by bat               #+#    #+#             */
/*   Updated: 2023/07/11 09:24:53 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eats(t_config *config)
{

}

void    sleeps(t_config *config)
{

}

void    thinks(t_config *config)
{

}

void	solo(t_config *config)
{
	int	start;

	start = get_time('n');
	while (start + config->t_die > get_time('n'))
		;
	msg(config, DIES);
	config->life = 0;
}