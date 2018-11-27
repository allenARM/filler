/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:00:07 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 16:52:22 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,\
		int (*cmpf)(void *, void *))
{
	if (!root || !data_ref)
		return (NULL);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->left)
		return (ft_btree_search_item(root->left, data_ref, cmpf));
	if (root->right)
		return (ft_btree_search_item(root->right, data_ref, cmpf));
	return (NULL);
}
