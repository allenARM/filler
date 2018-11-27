/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:59:42 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 16:52:07 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!*root || !root || !item)
	{
		if (root && item)
			*root = ft_btree_create_node(item);
		return ;
	}
	node = *root;
	if (cmpf(item, node->item) < 0)
	{
		if (node->left)
			ft_btree_insert_data(&node->left, item, cmpf);
		else
			node->left = ft_btree_create_node(item);
	}
	else
	{
		if (node->right)
			ft_btree_insert_data(&node->right, item, cmpf);
		else
			node->right = ft_btree_create_node(item);
	}
}
