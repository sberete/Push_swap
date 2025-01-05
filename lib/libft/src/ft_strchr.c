/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:29:36 by sxriimu           #+#    #+#             */
/*   Updated: 2024/11/12 17:19:45 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*retval;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == '\0' && (unsigned char)c != '\0')
		return (retval = 0);
	retval = (char *)s + i;
	return (retval);
}
/*
int	main(void)
{
	char	str[] = "Jei suis k";
	int		c;
	char	*x;

	c = 'i';
	x = ft_strchr(str, c);
	printf("%s", x);
}
*/