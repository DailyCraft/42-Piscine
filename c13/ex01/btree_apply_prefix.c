/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:08:48 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 22:18:33 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
/*
#include <stdio.h>
void	print(void *item)
{
	printf("%s\n", (char *) item);
}

int main()
{
	t_btree *btree = btree_create_node("1");
	btree->left = btree_create_node("2");
	btree->right = btree_create_node("3");
	btree->left->left = btree_create_node("4");
	btree->left->right = btree_create_node("5");
	btree->right->right = btree_create_node("6");
	btree->left->right->left = btree_create_node("7");
	btree->left->right->right = btree_create_node("8");
	btree->right->right->left = btree_create_node("9");
	btree_apply_prefix(btree, print);
}*/