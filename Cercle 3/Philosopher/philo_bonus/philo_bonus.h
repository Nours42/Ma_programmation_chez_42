/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:06:04 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 22:53:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "../includes/philo.h"

// to waitpid and wait

# include <sys/wait.h>

// to fork

# include <sys/types.h>

//to sem_open

# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

#endif