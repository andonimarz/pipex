/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:14:19 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/11 10:00:31 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int	ft_get_fd(char *file, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			ft_putstr_fd("Invalid or missing input file\n", 2);
			exit(0);
		}
		return (fd);
	}
	else
	{
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		return (fd);
	}
}

void	ft_check_cmd(int argc, char **argv, char **envp)
{
	char	*path;
	char	**argv_sp;
	int		i;

	i = 2;
	while (i <= (argc - 2))
	{
		argv_sp = ft_split(argv[i], ' ');
		path = ft_get_path(argv_sp, envp);
		if (!path)
		{
			free(path);
			ft_putstr_fd("invalid CMD: ", 2);
			ft_putendl_fd(argv_sp[0], 2);
			ft_free(argv_sp);
			exit(0);
		}
		else
		{
			ft_free(argv_sp);
			free(path);
		}
		i++;
	}
}

static char	**ft_make_path(char **argv_sp, char **envp)
{
	char	*path_str;
	char	**path_sp;
	int		i;

	i = 0;
	while (!(ft_strnstr(envp[i], "PATH=", 5)))
		i++;
	path_str = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	path_sp = ft_split((path_str), ':');
	free(path_str);
	i = 0;
	while (path_sp[i])
	{
		path_sp[i] = ft_strjoin_free(path_sp[i], "/");
		path_sp[i] = ft_strjoin_free(path_sp[i], argv_sp[0]);
		i++;
	}
	return (path_sp);
}

char	*ft_get_path(char **argv_sp, char **envp)
{
	int		i;
	char	**path_sp;
	char	*result;

	i = -1;
	path_sp = ft_make_path(argv_sp, envp);
	while (path_sp[++i])
	{
		if (!access(path_sp[i], F_OK))
		{
			result = ft_substr(path_sp[i], 0, ft_strlen(path_sp[i]));
			ft_free(path_sp);
			return (result);
		}
	}
	ft_free(path_sp);
	return (NULL);
}
