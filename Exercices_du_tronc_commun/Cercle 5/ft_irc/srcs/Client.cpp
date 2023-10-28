/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/28 18:52:40 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ircserv.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int					status, client_fd;
	struct sockaddr_in	serv_addr;
	std::string			hello = "Hello from client";
	char				buffer[1024] = { 0 };

	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (print_error("Socket creation error"));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
		return (print_error("Invalid address/ Address not supported"));
	if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
		return (print_error("Connexion failed"));
	send(client_fd, hello.c_str(), hello.length(), 0);
	std::cout << "Hello message sent" << std::endl;
	// valread = read(client_fd, buffer, 1024 - 1);
	std::cout << buffer << std::endl;
	close(client_fd);
	return (0);
}
