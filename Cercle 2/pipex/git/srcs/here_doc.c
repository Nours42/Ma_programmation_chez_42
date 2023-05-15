/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:29:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 21:31:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	find_nl(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

static char	*get_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
	{
		new_line[j] = str[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

static char	*trim_rem(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (some_error(rem));
	rd = 1;
	while (!find_nl(rem) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (some_error(buf));
		buf[rd] = '\0';
		rem = ft_strjoin(rem, buf);
	}
	free(buf);
	*line = get_line(rem);
	rem = trim_rem(rem);
	if (rd == 0 && !rem)
		return (0);
	return (1);
}

void	here_doc(char *argv, t_data *data)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error("Error in open heredoc process");
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	data->infile = open(".heredoc_tmp", O_RDONLY);
	if (data->infile < 0)
	{
		unlink(".heredoc_tmp");
		msg_error("Error in infile heredoc process");
	}
}
