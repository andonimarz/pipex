/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:13 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/05 17:02:49 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char *cmd, char **envp)
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

void	ft_pipex(char *cmd, char **envp, int fdin)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			ft_child(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdinfile;
	int	fdoutfile;

	if (argc < 5)
		ft_putstr_fd("Too few arguments. Check and try again\n", 2);
	else
	{
		i = 0;
		ft_check_cmd(argc, argv, envp);
		fdinfile = ft_get_fd(argv[++i], 0);
		fdoutfile = ft_get_fd(argv[argc - 1], 1);
		dup2(fdinfile, STDIN_FILENO);
		dup2(fdoutfile, STDOUT_FILENO);
		ft_pipex(argv[++i], envp, fdinfile);
		while (++i < (argc - 2))
			ft_pipex(argv[i], envp, 1);
		ft_child(argv[i], envp);
	}
	return (0);
}
