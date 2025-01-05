/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:44:41 by sxriimu           #+#    #+#             */
/*   Updated: 2024/11/09 22:44:42 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (len > ft_strlen(s))
		size = ft_strlen(s);
	else
		size = len;
	str = malloc(sizeof(char) * (size + 1));
	if (!s || !str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < size)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	str[] = "Je vais a l'ecole tout les jours";
	char	*x;

	x = ft_substr(str, 2, 8);
	printf ("%s", x);
}
*/