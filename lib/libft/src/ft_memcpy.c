/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:12:45 by sxriimu           #+#    #+#             */
/*   Updated: 2024/11/12 18:14:07 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		ft_memset((dest + i), *(unsigned char *)(src + i), 1);
		i++;
	}
	return (dest);
}

/*
int main()
{
	char src[15] = "Je suis Batman";
	char dest[6];

	ft_memcpy(dest, src, 15);
	printf("%s", dest);
}
*/