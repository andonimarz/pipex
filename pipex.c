/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:13 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/05 14:48:56 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child_1(int *fd, char **argv, char **envp)
{
	int		fd_infile;
	char	**argv_sp;
	char	*path;

	close(fd[0]);
	fd_infile = ft_get_fd(argv[1], 0);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	argv_sp = ft_split(argv[2], ' ');
	path = ft_get_path(argv_sp, envp);
	if (execve(path, argv_sp, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(argv_sp[0], 2);
		ft_free(argv_sp);
		free(path);
		exit(0);
	}
}

static void	ft_child_2(int *fd, char **argv, char **envp)
{
	int		fd_outfile;
	char	**argv_sp;
	char	*path;

	close(fd[1]);
	fd_outfile = ft_get_fd(argv[4], 1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_outfile, STDOUT_FILENO);
	argv_sp = ft_split(argv[3], ' ');
	path = ft_get_path(argv_sp, envp);
	if (execve(path, argv_sp, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(argv_sp[0], 2);
		ft_free(argv_sp);
		free(path);
		exit(0);
	}
}

static void	ft_pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork ();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
		ft_child_1(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
			ft_child_2(fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Invalid argument number. Check and try again\n", 2);
		exit(0);
	}
	ft_check_cmd(argc, argv, envp);
	ft_pipex(argv, envp);
	return (0);
}
