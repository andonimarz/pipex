/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:43:45 by amarzana          #+#    #+#             */
/*   Updated: 2022/06/24 17:17:08 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	return (NULL);
}

/* int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**argv_sp;

	(void)argc;
	argv_sp = ft_split(argv[1], ' ');
	path = ft_get_path(argv_sp, envp);
	printf("%s\n", path);
	ft_free(argv_sp);
	free (path);
	return (0);
} */
