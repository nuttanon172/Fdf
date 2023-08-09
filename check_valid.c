/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:36:17 by ntairatt          #+#    #+#             */
/*   Updated: 2023/08/09 12:42:03 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_prefix(char *s, int base)
{
	int	i;

	i = 0;
	if (s[i] == '0')
		i++;
	if ((base == 16) && (s[i] == 'X' || s[i] == 'x'))
		return (1);
	return (0);
}

int	ft_isvalid(char *s, int base)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v')
		|| (s[i] == '\f') || (s[i] == '\r'))
		i++;
	if (base == 16 && !ft_prefix(&s[i], base))
		return (0);
	if (base == 16)
		i += 2;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	while (ft_isbase(s[i], base) >= 0)
	{
		i++;
		digit++;
	}
	if ((s[i] == '\0') || digit)
		return (1);
	else
		return (0);
}