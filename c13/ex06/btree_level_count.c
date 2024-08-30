/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:43:24 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:55:12 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (root == NULL)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (1 + left);
	return (1 + right);
}
/*
#include <stdio.h>
int main()
{
	t_btree *tree = btree_create_node("");
	tree->left = btree_create_node("");
	tree->left->left = btree_create_node("");
	tree->left->left->left = btree_create_node("");
	tree->left->right = btree_create_node("");
	tree->right = btree_create_node("");
	tree->right->left = btree_create_node("");
	tree->right->left = btree_create_node("");
	printf("%d", btree_level_count(tree));
}*/