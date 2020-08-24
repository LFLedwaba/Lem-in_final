
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkebethi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:21:19 by lkebethi          #+#    #+#             */
/*   Updated: 2019/07/04 16:32:23 by lkebethi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_jointostr(char *s, char *buf)
{
	char *limited;

	if (!s)
		return (NULL);
	limited = ft_strjoin(s, buf);
	free(s);
	return (limited);
}