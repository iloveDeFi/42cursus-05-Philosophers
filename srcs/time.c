/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:49:30 by bat               #+#    #+#             */
/*   Updated: 2023/07/11 08:47:50 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* if flag == 'i', initializes the timeofday,
	if flag == 'n', returns the time as of now
	else return the difference with the current time */
int	get_time(char c)
{
	static struct timeval	start_time;
	struct timeval			tv;

	if (c == 'i')
	{
		gettimeofday(&start_time, NULL);
		return (0);
	}
	else if (c == 'n')
	{
		gettimeofday(&tv, NULL);
		return ((tv.tv_sec - start_time.tv_sec) * 1000
			+ (tv.tv_usec - start_time.tv_usec) / 1000);
	}
	return (0);
}