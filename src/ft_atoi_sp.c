/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:36:17 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/08 12:46:54 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ishex(char *s)
{
	if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'))
		return (1);
	return (0);
}

int	base_check(char c, int base_num)
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

int	ft_isvalid(char *s, int base)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (base == 16 && !ft_ishex(&s[i]))
		return (0);
	if (base == 16)
		i += 2;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	while (base_check(s[i], base) >= 0)
	{
		i++;
		digit++;
	}
	if ((s[i] == '\0') || digit)
		return (1);
	else
		return (0);
}

int	ft_atoi_base(char *str, int base_num)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_ishex(str) && base_num == 16)
		return (0);
	i += 2;
	while (base_check(str[i], base_num) >= 0)
	{
		result = (result * base_num) + (base_check(str[i], base_num));
		i++;
	}
	return ((int)(result));
}

int	ft_atoi_sp(const char *str, t_map *map, t_node_z **stack)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
