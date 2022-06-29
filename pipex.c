/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:13 by amarzana          #+#    #+#             */
/*   Updated: 2022/06/28 18:45:01 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child_start(int *fd, char **argv, char **envp)
{
	int		fd_infile;
	char	**argv_sp;
	char	*path;

	close(fd[0]);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		perror("Error");
		exit(0);
	}
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

static void	ft_child_n(int *fd1, int *fd2, char *cmd, char **envp)
{
	int		fd_infile;
	char	**cmd_sp;
	char	*path;

	close(fd2[0]);
	dup2(fd1[0], STDIN_FILENO);
	close(fd1[0]);
	dup2(fd2[1], STDOUT_FILENO);
	close(fd2[1]);
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

static void	ft_child_end(int *fd, int argc, char **argv, char **envp)
{
	int		fd_outfile;
	char	**argv_sp;
	char	*path;

	close(fd[1]);
	fd_outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		perror("Error");
		exit(0);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_outfile, STDOUT_FILENO);
	argv_sp = ft_split(argv[argc - 2], ' ');
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

static void	ft_pipex(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int		fd1[2];
	int		fd2[2];

	pipe(fd1);
	pid = fork ();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
		ft_child_start(fd1, argv, envp);
	else
	{
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
			ft_child_end(fd1, argc, argv, envp);
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd1[0]);
			close(fd1[1]);
		}
	}
	waitpid(pid, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	cmd_nb;

	if (argc < 5)
	{
		ft_putstr_fd("Too few arguments. Check and try again\n", 2);
		exit(0);
	}
	ft_check_infile(argv);
	cmd_nb = ft_check_cmd(argc, argv, envp);
	ft_pipex(argc, argv, envp);
	return (0);
}
