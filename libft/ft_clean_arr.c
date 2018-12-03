/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:44 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/27 14:47:58 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clean_arr(char ***argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*argv)[i])
		return ;
	while ((*argv)[i])
		i++;
	while (j < i)
	{
		free((*argv)[j]);
		j++;
	}
	free(*argv);
}
