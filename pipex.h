/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:28:25 by amarzana          #+#    #+#             */
/*   Updated: 2022/06/28 18:32:07 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*			includes		*/
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/*			argv			*/
/* # define RD_FILE	1
# define CMD1		2
# define CMD2		3
# define WR_FILE	4 */

/*			libft			*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

/*			get_path		*/
char	*ft_get_path(char **argv_sp, char **envp);

/*			utils			*/
void	ft_free(char **ptr);
void	ft_check_infile(char **argv);
int		ft_check_cmd(int argc, char **argv, char **envp);

#endif