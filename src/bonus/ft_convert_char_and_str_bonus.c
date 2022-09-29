/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_and_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:05:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/28 23:23:01 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	convert_c_and_percent(t_printf_info *info, va_list args)
{
	size_t				counter;

	counter = 0;
	if (info->spec == '%')
		counter += ft_putchar_fd('%', 1);
	if (info->spec == 'c')
	{
		while (info->width-- > 1)
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	}
	return (counter);
}

size_t	convert_s(t_printf_info *info, va_list args)
{
	size_t	counter;
	char	*str;

	counter = 0;
	str = va_arg(args, char *);
	str = ft_strdup(str);
	if (info->prec >= 0)
		str = get_precision_s(info, &str);
	if (info->width >= 0)
		str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free(str);
	return (counter);
}