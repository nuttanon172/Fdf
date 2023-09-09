/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:36:17 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 15:58:23 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ishex(char *s)
{
	if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'))
		return (1);
	return (0);
}

int	ft_hexnbr(char c, int base_num)
{
	char	*base_char;
	int		i;

	base_char = "0123456789ABCDEF";
	i = 0;
	while (i < base_num)
	{
		if ((base_char[i] == ft_toupper(c)) || (base_char[i] == '\n'))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_format(char *s, int base)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (base == 16 && !ft_ishex(&s[i]))
		return (0);
	if (base == 16)
		i += 2;
	while (ft_hexnbr(s[i], base) >= 0)
	{
		i++;
		digit++;
	}
	if ((s[i] == '\0') || digit)
		return (1);
	else
		return (0);
}

int	ft_color(char *str, int base_num)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_ishex(str) && base_num == 16)
		return (-1);
	i += 2;
	while (ft_hexnbr(str[i], base_num) >= 0)
	{
		result = (result * base_num) + (ft_hexnbr(str[i], base_num));
		i++;
	}
	return (result);
}
