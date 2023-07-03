/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:25:26 by bat               #+#    #+#             */
/*   Updated: 2023/07/03 14:39:20 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void    *myturn(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("My Turn\n");
    }
    return NULL;
}

void    yourturn()
{
    while (1)
    {
        sleep(2);
        printf("Your Turn\n");
    }
}

int main()
{
    pthread_t newthread;

    pthread_create(&newthread, NULL, myturn, NULL);
    //myturn();
    yourturn();
    return (0);
}