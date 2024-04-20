/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:16:34 by aait-lha          #+#    #+#             */
/*   Updated: 2024/04/19 22:46:34 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_checker_bonus.h"

int	get_next_line(char **line)
{
	char	ch;
	int		nb_bytes;
	int		i;

	ch = 0;
	nb_bytes = 1;
	i = 0;
	*line = malloc(10000);
	if (!*line)
		return (*line = NULL, 0);
	while (1)
	{
		nb_bytes = read(0, &ch, 1);
		if (nb_bytes == -1)
			return (free(*line), 0);
		if (!nb_bytes)
			return 0;
		if (ch && ch != '\n' && ch != '\0')
			(*line)[i++] = ch;
		else
			break ;
	}
    (*line)[i++] = '\n';
    (*line)[i] = '\0';
	return (1);
}
