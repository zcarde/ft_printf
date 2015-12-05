/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:05:00 by zcarde            #+#    #+#             */
/*   Updated: 2015/12/03 05:00:48 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# define HH		1
# define H		2
# define LL		3
# define L		4
# define J		5
# define Z		6

typedef struct	s_info
{
	int			diez;
	int			zero;
	int			moins;
	int			plus;
	int			espace;
	size_t		size_min;
	size_t		precis;
	char		conv;
	int			sm;
}				t_info;
void	ftprintf_putchar(char c);
void	ftprintf_putstr(char const *s);
char	*ftprintf_strdup(char *s1);
char	*ftprintf_strchr(const char *s, int c);
char	*ftprintf_strjoinlf(char *s1, char *s2);
char	*ftprintf_strjoinrf(char *s1, char *s2);
char	*ftprintf_strjoindf(char *s1, char *s2);
char	*ftprintf_strjoin(char *s1, char *s2);

size_t	ftprintf_strlen(const char *str);
char	*ftprintf_strsub(char *s, unsigned int start, size_t len);
char	*ftprintf_strsubf(char *s, unsigned int start, size_t len);
char	*ftprintf_itoa(int n);
int		ftprintf_atoi(const char *str);
int		ft_printf(char *str, ...);

#endif