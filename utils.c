/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:14:19 by amarzana          #+#    #+#             */
/*   Updated: 2022/06/28 18:30:54 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	ft_check_infile(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_putstr_fd("Invalid or missing input file. Check and try again\n", 2);
		exit(0);
	}
	close(fd);
}

int	ft_check_cmd(int argc, char **argv, char **envp)
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
			ft_putstr_fd("invalid CMD: ", 2);
			ft_putendl_fd(argv_sp[0], 2);
			ft_free(argv_sp);
			free(path);
			exit(0);
		}
		i++;
	}
	return (i - 2);
}
