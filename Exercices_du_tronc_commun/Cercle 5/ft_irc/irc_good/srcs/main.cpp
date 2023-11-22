/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/22 13:20:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

int main(int argc, char const* argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: ./ircserv [port] [password]"<<std::endl;
		return 0;
	}

	std::string		message;
	std::string		buffer;
	int				rc = 1, \
					i = 0, \
					fdsId = 1, \
					newSd = 0, \
					close_conn = 0;

	Server			*server;
	try
	{
		server = new Server(argv[1], argv[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR] : Error during server creation : " << std::endl;
		std::cerr <<  e.what() << std::endl;
		delete server;
	}

	while (1)
	{
		std::cout << YELLOW << "Waiting incoming connection ( poll() )..." << RESET << std::endl;
		rc = poll(&(server->fds[0]), fdsId, -1);
		server->current_size = fdsId;
		for (int i = 0; i < server->current_size; i++)
		{
			if(server->fds[i].revents == 0)
				continue;
			newSd = 0;
			if (server->fds[i].fd == server->getServerSocket())
			{
				while (newSd != -1)
				{
					newSd = accept(server->getServerSocket(), NULL, NULL);
					if (newSd != -1)
					{
						try
						{
							std::cout << YELLOW << "New user connected with id " << newSd << "." << RESET << std::endl;
							server->newUser(newSd);
							fdsId++;
						}
						catch (const std::exception& e)
						{
							std::cerr << ERROR << "Error during user creation : " << std::endl;
							std::cerr <<  e.what() << RESET << std::endl;
							server->deleteUser(newSd);
							close(newSd);
						}
					}
				}
			}
			else if (server->fds[i].fd == -1)
				break;
			else
			{
				buffer.resize(BUFFSIZE);
				rc = recv(server->fds[i].fd, &buffer[0], sizeof(buffer), 0);
				if (rc == 0)
				{
					std::cout << YELLOW << "Receiving ctrl c from id " << server->fds[i].fd << ", erasing user." << RESET << std::endl;
					close(server->fds[i].fd);
					server->deleteUser(server->fds[i].fd);
					server->checkChannel();
					server->fds[i].fd = -1;
					std::cout << DELETE << "User succesfully deleted" << RESET << std::endl;
					std::cout << DIVIDER << RESET << std::endl;
					continue;
				}
				buffer.resize(rc);
				std::string strmess = buffer;
				read_log(server->fds[i].fd, buffer, server);
				if (!server->haveN(strmess))
				{
					strmess = server->writeLoop(server->fds[i].fd, strmess);
					interpretor((char*)strmess.c_str(), server->fds[i].fd, server);
					std::cout << DIVIDER << RESET << std::endl;
				}
				else
					interpretor(&buffer[0], server->fds[i].fd, server);
			}
			std::cout << DIVIDER << RESET << std::endl;
		}
	}
	std::cout << "END OF PROGRAM" << std::endl;
	return 0;
}