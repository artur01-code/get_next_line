/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:36:41 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/22 14:09:52 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_or(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0' && s[size] != '\n')
		size++;
	if (s[size] == '\n')
		return (size + 1);
	else
		return (size);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc (nmemb * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (s == 0)
		return (0);
	i = 0;
	len = ft_strlen_or(s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = ft_calloc((ft_strlen_or(s1)+ ft_strlen_or(s2) + 1), sizeof(char));
	if (s2 == 0 || s3 == 0)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s2);
	return (s3);
}
