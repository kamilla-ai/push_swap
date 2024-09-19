/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:15:21 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/18 17:20:07 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*putstr(const char *s, char c, int *current)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[*current] != '\0' && s[*current] == c)
		(*current)++;
	while (s[*current + len] != '\0' && s[*current + len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[*current];
		(*current)++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

static int	numberofstrings(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**allocateresult(char const *s, char c)
{
	char	**result;
	int		count;

	count = numberofstrings(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 2));
	if (result == NULL)
		return (NULL);
	result[0] = (char *)malloc(sizeof(char));
	if (result[0] == NULL)
	{
		free(result);
		return (NULL);
	}
	result[0][0] = '\0';
	return (result);
}

char	**ps_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		current;

	if (s == NULL)
		return (NULL);
	result = allocateresult(s, c);
	if (result == NULL)
		return (NULL);
	current = 0;
	i = 1;
	while (i < numberofstrings(s, c) + 1)
	{
		result[i] = putstr(s, c, &current);
		if (result[i] == NULL)
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
