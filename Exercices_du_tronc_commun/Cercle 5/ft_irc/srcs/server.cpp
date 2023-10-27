/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/23 17:24:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"

int	print_error(std::string str)
{
	std::cerr << str << std::endl;
	return (-1);
}

int main(int argc, char const* argv[])
{
	int					server_fd, new_socket;
	ssize_t				valread;
	struct sockaddr_in	address;
	int					opt = 1;
	socklen_t			addrlen = sizeof(address);
	char				buffer[1024] = { 0 };
	char				*hello = "Hello from server";

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (print_error("socket failed"));
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
		return (print_error("setsockopt"));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
		return (print_error("bind failed"));
	if (listen(server_fd, 3) < 0)
		return (print_error("listen"));
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0)
		return (print_error("accept"));
	valread = read(new_socket, buffer, 1024 - 1);
	std::cout << buffer << std::endl;
	send(new_socket, hello, strlen(hello), 0);
	std::cout << "Hello message sent" << std::endl;
	close(new_socket);
	close(server_fd);
	return (0);
}