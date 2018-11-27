/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:00:51 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 16:52:11 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		maxnum(int count, int max)
{
	if (count > max)
		return (count);
	else
		return (max);
}

int				ft_btree_level_count(t_btree *root)
{
	int			count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = maxnum(count, ft_btree_level_count(root->left));
	if (root->right)
		count = maxnum(count, ft_btree_level_count(root->right));
	return (count + 1);
}
