/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:42:33 by sxriimu           #+#    #+#             */
/*   Updated: 2024/11/09 22:42:34 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*retval;

	i = 0;
	retval = (char *)s + i;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			retval = (char *)s + i;
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		retval = (char *)s + i;
		return (retval);
	}
	if (*retval != (unsigned char)c)
		return (retval = 0);
	return (retval);
}
/*
int	main(void)
{
	char	str[] = "Je suis k";
	int		c;
	char	*x;

	c = 'i';
	x = ft_strrchr(str, c);
	printf("%s", x);
}
*/