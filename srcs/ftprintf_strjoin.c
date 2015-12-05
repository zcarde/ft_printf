/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:51:35 by zcarde            #+#    #+#             */
/*   Updated: 2015/12/03 04:57:22 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ftprintf_strjoindf(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return ((!s2) ? NULL : s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * (ftprintf_strlen(s1) +
			ftprintf_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	free(s1);
	free(s2);
	str[i] = '\0';
	return (str);
}

char	*ftprintf_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return ((!s2) ? NULL : s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * (ftprintf_strlen(s1) +
			ftprintf_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ftprintf_strjoinrf(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return ((!s2) ? NULL : s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * (ftprintf_strlen(s1) +
			ftprintf_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	free(s2);
	str[i] = '\0';
	return (str);
}

char	*ftprintf_strjoinlf(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return ((!s2) ? NULL : s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * (ftprintf_strlen(s1) +
			ftprintf_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
