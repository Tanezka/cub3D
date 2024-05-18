/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:29:31 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:29:33 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_str_toupper(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		*ptr = ft_toupper(*ptr);
		ptr++;
	}
	return (str);
}
