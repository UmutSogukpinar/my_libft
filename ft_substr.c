/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:31:25 by usogukpi          #+#    #+#             */
/*   Updated: 2024/10/19 20:29:24 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	if (start > ft_strlen(s))
	{
		arr = malloc(1);
		arr[0] = '\0';
		return (arr);
	}
	if (start + len > ft_strlen(s))
		arr = malloc(ft_strlen(s) - start + 1);
	else
		arr = malloc(len + 1);
	if (!arr || !s)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
