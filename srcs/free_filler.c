/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:19:46 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/28 15:19:46 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_filler(t_filler *filler)
{
	int	i;

	i = 0;
	ft_clean_arr(&filler->map.field);
	ft_clean_arr(&filler->piece.field);
}
