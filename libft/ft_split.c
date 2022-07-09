/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:34:16 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/09 03:48:05 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_coincidences(char const *s, char c)
{
	int	coin;
	int	i;

	i = 0;
	coin = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != 39)
			coin++;
		while (s[i] && (s[i] != c || s[i] == 39))
		{
			if (s[i] == 39)
			{
				coin++;
				i++;
				while (s[i] && s[i] != 39)
					i++;
			}
			i++;
		}
		if (s[i])
			i++;
	}
	return (coin);
}

char	*ft_make_str(char const *s, char c, int i)
{
	char	*str_row;
	int		counter;

	counter = i;
	if (s[counter++] == 39)
	{
		while (s[counter] && s[counter] != 39)
			counter++;
		str_row = ft_substr(s, i + 1, counter - i - 1);
	}
	else
	{
		while (s[counter] && s[counter] != c)
			counter++;
		str_row = ft_substr(s, i, counter - i);
	}
	return (str_row);
}

char	*ft_get_row(char const *s, char c, int row)
{
	int		i;
	int		counter;
	char	*str_row;

	str_row = NULL;
	i = -1;
	counter = -1;
	while (++i < (int)ft_strlen(s) && s[i])
	{
		if (s[i] != c)
			counter++;
		if (counter == row && s[i] != c)
		{
			str_row = ft_make_str(s, c, i);
			if (!str_row)
				return (NULL);
		}
		while (s[i] && s[i] != c)
			if (s[i++] == 39)
				while (s[i] && s[i] != 39)
					i++;
	}
	return (str_row);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		coin;
	int		i;

	if (!s)
		return (NULL);
	coin = ft_coincidences(s, c);
	if (c == '\0' && ft_strlen(s) > 0)
		coin = 1;
	split = (char **)malloc((coin + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < coin)
	{
		split[i] = ft_get_row(s, c, i);
		if (split[i] == NULL)
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
