#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

// Déclaration des variables globales

int			max_fd; // Le plus grand descripteur de fichier
int			arr_id[5000]; // Tableau d'identifiants clients
char		*arr_str[5000]; // Tableau de chaînes de caractères pour les données des clients
char		*message = NULL; // Pointeur vers un message
char		buff_send[100]; // Buffer pour l'envoi de messages
char		buff_read[1001]; // Buffer pour la lecture de messages
fd_set		actual_set; // Ensemble de descripteurs actifs
fd_set		read_set; // Ensemble de descripteurs en lecture
fd_set		write_set; // Ensemble de descripteurs en écriture


//	Fonction extract_message

// Cette fonction extrait un message d'un buffer.
// Elle recherche un caractère de saut de ligne (\n) dans le buffer.
// Si elle en trouve un, elle sépare le message du reste du buffer et met à jour
// les pointeurs.
// Elle renvoie 1 si un message a été extrait avec succès, 0 si aucun message
// n'est disponible, et -1 en cas d'erreur.

int	extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int		i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

// Fonction str_join

// Cette fonction concatène deux chaînes de caractères (buf et add) pour former
// une nouvelle chaîne. Elle gère la mémoire dynamiquement pour la nouvelle
// chaîne résultante et retourne cette chaîne.

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

// Fonction print

// Une fonction utilitaire pour imprimer un message sur un descripteur de
// fichier spécifié (fd) et quitter le programme ensuite.

void print(int fd, char *str)
{
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	exit(1);
}

// Fonction send_msg

// Cette fonction envoie un message à tous les clients connectés, sauf au client
// spécifié par le descripteur fd.

void send_msg(int fd)
{
	for (int current_fd = 3; current_fd <= max_fd; current_fd++)
	{
		if (FD_ISSET(current_fd, &write_set) && current_fd != fd)
		{
			send(current_fd, buff_send, strlen(buff_send), 0);
			if (message)
				send(current_fd, message, strlen(message), 0);
		}
	}
}

// Fonction main

// La fonction principale du programme.
// Elle vérifie le nombre d'arguments fournis en ligne de commande et crée un
// socket, lie l'adresse IP et le port spécifiés, puis écoute les connexions
// entrantes.
// Elle utilise select pour gérer les événements de lecture et d'écriture sur
// les descripteurs de fichiers.
// Si un client se connecte, il est ajouté à l'ensemble des descripteurs actifs.
// Le code gère également la réception de messages des clients, leur stockage
// dans des buffers, l'extraction et l'envoi de ces messages à tous les autres
// clients connectés.

int main(int argc, char **argv)
{

	// Déclaration de variables pour les sockets et les adresses
	int					sockfd;
	int					connfd;
	socklen_t			len;
	struct sockaddr_in	servaddr;
	struct sockaddr_in	cli;

	if (argc != 2)
		print(2, "Wrong number of arguments");

	// creation du socket et verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		print(2, "Fatal error");
	bzero(&servaddr, sizeof(servaddr));

	// configuration de l'adresse IP et du PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

    // Liaison du socket et vérification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		print(2, "Fatal error");
	if (listen(sockfd, 10) != 0)
		print(2, "Fatal error");

    // Initialisation des ensembles de descripteurs et d'autres variables
	len = sizeof(cli);

	max_fd = sockfd;
	FD_ZERO(&actual_set);
	FD_SET(sockfd, &actual_set);
	int clientid = 0;

	while(1)
	{
		// Mise à jour des ensembles de descripteurs
		read_set = write_set = actual_set;

		// Gestion des événements de lecture et d'écriture sur les descripteurs de fichiers
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) <= 0)
			continue;

		if (FD_ISSET(sockfd, &read_set))
		{
			// Nouvelle connexion entrante
			connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
			if (connfd < 0) {
				print(2, "Fatal error");
			}

            // Gestion de l'arrivée d'un nouveau client
			arr_id[connfd] = clientid++;
			FD_SET(connfd, &actual_set);
			max_fd = connfd > max_fd ? connfd : max_fd;
			sprintf(buff_send, "server: client %d just arrived\n", arr_id[connfd]);
			send_msg(connfd);
			arr_str[connfd] = NULL;
			continue;
		}

		for (int fd = 3; fd <= max_fd; ++fd)
		{
			if (FD_ISSET(fd, &read_set) && fd != sockfd)
			{
				// Réception de messages des clients
				int count = recv(fd, buff_read, 1000, 0);
				if (count <= 0)
				{
			       // Gestion de la déconnexion d'un client
					FD_CLR(fd, &actual_set);
					sprintf(buff_send, "server: client %d just left\n", arr_id[fd]);
					send_msg(fd);
					close(fd);
					if (arr_str[fd] != NULL)
						free(arr_str[fd]);
					break;
				}
				else
				{
                    // Traitement des messages reçus
					buff_read[count] = '\0';
					arr_str[fd] = str_join(arr_str[fd], buff_read);
					message = NULL;
					while (extract_message(&arr_str[fd], &message))
					{
                        // Extraction et envoi de messages aux autres clients
						sprintf(buff_send, "client %d: ", arr_id[fd]);
						send_msg(fd);
						free(message);
						message = NULL;
					}
				}
			}
		}
	}
	return (0);
}
