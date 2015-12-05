/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:02:48 by zcarde            #+#    #+#             */
/*   Updated: 2015/12/03 05:05:28 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//FLAGS CONVERSION  sSpdDioOuUxXcC
int		is_end_char(char c)
{
	if (c == '%')
		return (1);
	if (c == 's' || c == 'S')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd' || c == 'D')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'o' || c == 'O')
		return (1);
	if (c == 'u' || c == 'U')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == ' ')
		return (1);
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	if (c == '#')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_pos_number(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

void	init_struct(t_info *info)
{
	info->diez = 0;
	info->zero = 0;
	info->moins = 0;
	info->plus = 0;
	info->espace = 0;
	info->size_min = 0;
	info->precis = -1;
	info->conv = 0;
	info->sm = 0;
}

int		size_format(char *str)
{
	int		i;

	i = 0;
	while (str[i] && !is_end_char(str[i]))
		i++;
	return (i + 1);
}

void	print_struct(t_info info)
{
	printf("Conversion (%%%c)\n\tdiez[%d]\n\tzero[%d]\n\tmoins[%d]\n\tplus[%d]\n\tespace[%d]\n"
		, info.conv, info.diez, info.zero, info.moins, info.plus, info.espace);
	printf("\tmin[%zu]\n", info.size_min);
	printf("\tprecision[%zu]\n", info.precis);
	if (info.sm == HH)
		printf("\tsize modifier[HH]\n");
	if (info.sm == H)
		printf("\tsize modifier[H]\n");
	if (info.sm == LL)
		printf("\tsize modifier[LL]\n");
	if (info.sm == L)
		printf("\tsize modifier[L]\n");
	if (info.sm == J)
		printf("\tsize modifier[J]\n");
	if (info.sm == Z)
		printf("\tsize modifier[Z]\n");
}

void	check_flag(t_info *info, char *format)
{
	if (*format == '#')
		info->diez = 1;
	if (*format == '0')
		info->zero = 1;
	if (*format == '-')
		info->moins = 1;
	if (*format == '+')
		info->plus = 1;
	if (*format == ' ')
		info->espace = 1;
}

int		check_size_modifier(char *format)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			return (HH);
		else
			return (H);
	}
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			return (LL);
		else
			return (L);
	}
	if (*format == 'j')
		return (J);
	if (*format == 'z')
		return (Z);
	return (0);
}

void	verify_struct(t_info *info)
{
	if (info->conv == 's' && info->sm == L)
		info->conv = 'S';
}

void	fill_struct(t_info *info, char *format)
{
	while (*format && is_flag(*format))
	{
		check_flag(info, format);
		info->sm = check_size_modifier(format);
		format++;
	}
	if (is_pos_number(*format))
		info->size_min = ftprintf_atoi(format);
	while (is_number(*format))
		format++;
	if (*format == '.')
	{
		format++;
		info->precis = ftprintf_atoi(format);
	}
	while (is_number(*format))
		format++;
	info->conv = *format;
	verify_struct(info);
}

char	*fill_str(t_info info, char *str, size_t nb)
{
	(void)info;
	size_t	i;

	i = 0;
	while (i < nb)
	{
		if (info.moins)
			str = ftprintf_strjoinlf(str, ((info.zero)? "0" : " "));
		else
			str = ftprintf_strjoinrf(((info.zero)? "0" : " "), str);
		i++;
	}
	// printf("[%zu]\n", nb);
	return (str);
}

char	*s_conv(t_info info, va_list ap)
{
	char	*str;
	char	*tmp;

	str = va_arg(ap, char *);
	if (!str)
		return ("(null)");
	tmp = ftprintf_strdup(str);
	if (info.precis < ftprintf_strlen(tmp) && info.precis != (size_t)-1)
		tmp = ftprintf_strsub(tmp, 0, info.precis);
	if (info.size_min > ftprintf_strlen(tmp) && info.size_min != 0)
		tmp = fill_str(info, tmp, info.size_min - ftprintf_strlen(tmp));
	return (tmp);
}

char	*goto_good_conv(t_info info, va_list ap)
{
	(void)info;
	if (info.conv == 's')
		return (s_conv(info, ap));
	return (NULL);
}

char	*get_formated_string(char *format, va_list ap)
{
	t_info info;

	if (*format == '%' || *format == '\0')
		return ("%");
	init_struct(&info);
	fill_struct(&info, format);
	// print_struct(info);
	return (goto_good_conv(info, ap));
	// return ("--");
}

int		ft_printf(char *str, ...)
{
	int		i;
	va_list	ap;
	char	*c;
	char	*ret;

	i = 0;
	va_start(ap, str);
	ret = (char *)malloc(sizeof(char) * 1);
	ret[0] = 0;
	// printf("FT_PRINTF(%s)\n", str);
	while ((c = ftprintf_strchr(str, '%')))
	{
		ret = ftprintf_strjoindf(ret, ftprintf_strsub(str, 0, c - str));
		str = c + size_format(c + 1) + 1;
		ret = ftprintf_strjoinlf(ret, get_formated_string(c + 1, ap));
	}
	ret = ftprintf_strjoinlf(ret, str);
	// printf("RESULT (%s)\n", ret);
	va_end(ap);
	ftprintf_putstr(ret);
	return (ftprintf_strlen(ret));
}