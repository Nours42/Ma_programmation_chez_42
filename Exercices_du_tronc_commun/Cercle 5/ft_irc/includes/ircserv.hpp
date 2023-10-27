/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 10:22:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BIBLIOGRAPHY //

// explication des sockets, setsock, bind, ... :
// https://www.geeksforgeeks.org/socket-programming-cc/ //

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

# include <iomanip>
# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

#define PORT 8080

int	print_error(std::string str);


#endif