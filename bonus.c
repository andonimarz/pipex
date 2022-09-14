/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:13 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/14 15:59:11 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static void	ft_child(char *cmd, char **envp)
{
	char	**cmd_sp;
	char	*path;

	cmd_sp = ft_split(cmd, ' ');
	path = ft_get_path(cmd_sp, envp);
	if (execve(path, cmd_sp, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_sp[0], 2);
		ft_free(cmd_sp);
		free(path);
		exit(0);
	}
}

static void	ft_pipex(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close (fd[1]);
		ft_child(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		wait(NULL);
	}
}

static void	ft_dups(int argc, char **argv)
{
	int	fdin;
	int	fdout;

	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		fdin = ft_get_fd(argv[2], 0);
		fdout = ft_get_fd(argv[argc - 1], 2);
	}
	else
	{
		fdin = ft_get_fd(argv[1], 0);
		fdout = ft_get_fd(argv[argc - 1], 1);
	}
	dup2(fdin, STDIN_FILENO);
	close (fdin);
	dup2(fdout, STDOUT_FILENO);
	close (fdout);
}

int	ft_check_input(char **argv)
{
	int	i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
			i = 3;
	else
			i = 2;
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	pid;

	if (argc < 5)
		ft_putstr_fd("Too few arguments. Check and try again\n", 2);
	else
	{
		i = ft_check_input(argv);
		ft_check_cmd(argc, argv, envp, i);
		ft_dups(argc, argv);
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
		{
			while (i < (argc - 2))
				ft_pipex(argv[i++], envp);
			ft_child(argv[i], envp);
		}
		else
			wait(NULL);
	}
	return (0);
}
