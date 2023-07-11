/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:02:16 by bat               #+#    #+#             */
/*   Updated: 2023/07/11 15:50:17 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define EATS 1
# define SLEEPS 2
# define THINKS 3
# define DIES 4
# define FORKS 5

typedef struct s_philo
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_time_eat;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*sim_mutex;
	int				*sim_state;
}				t_philo;

typedef struct s_config
{
	int				pos;
	int				next_pos;
	int				nb_philo;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				nb_t_eat;
	int				life;
	int				ate;
	int				last_bite;
	int				*sim_state;
	pthread_mutex_t	*sim_mutex;
	pthread_mutex_t	*forks;
}				t_config;

// actions.c
void		eats(t_config *config);
void		sleeps(t_config *config);
void		thinks(t_config *config);
void		solo(t_config *config);

// errors_and_messages.c
int			is_positive_number(char *str);
int			infos_check(int nb_args, char **infos);
int			error_msg(char flag);
void		msg(t_config *config, int status)

// free_and_finish.c
void		free_and_finish(t_philo *philo);

// main.c
void	initialize(t_philo *philo, char **settings);
void	initialize_next(t_philo *philo);
int		ft_atoi(const char *str);

// simulation.c
void		launch_sim(t_philo **philo);
int			satiated(t_config *config);
void		create_philo(t_philo *philo);
void		create_thread(t_philo *philo, int nb_philo);
void		*philo_day(void	*config);

// state.c
int			state(t_config *config);
void		state_update(t_config *config, char flag);

// time.c
int			get_time(char c);

#endif