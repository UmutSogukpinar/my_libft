/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:48:22 by usogukpi          #+#    #+#             */
/*   Updated: 2024/10/19 13:19:28 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_is_sep(char c, char sep)
{
	return (c == sep);
}

int static	ft_count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_sep(str[i], c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_is_sep(str[i], c))
			i++;
	}
	return (count);
}

char static	*ft_get_word(char *str, char sep, int i)
{
	char	*arr;
	int		original_i;
	int		j;
	int		len;

	original_i = i;
	j = 0;
	while (!ft_is_sep(str[i], sep) && str[i] != '\0')
		i++;
	len = i - original_i;
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (j < len)
	{
		arr[j] = str[original_i];
		original_i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		count;

	i = 0;
	count = ft_count_strings((char *) s, c);
	strings = malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_is_sep(s[i], c))
			i++;
		if (s[i] != '\0' && !ft_is_sep(s[i], c))
		{
			strings[count] = ft_get_word((char *) s, c, i);
			count++;
		}
		while (s[i] != '\0' && !ft_is_sep(s[i], c))
			i++;
	}
	strings[count] = NULL;
	return (strings);
}
