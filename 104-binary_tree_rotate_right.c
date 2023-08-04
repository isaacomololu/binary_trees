#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *pivot_l;

	if (tree != NULL && tree->left != NULL)
	{
		pivot_l = tree->left;
		temp = pivot_l->right;
		pivot_l->right = tree;
		tree->left = temp;
		if (temp != NULL)
			temp->parent = tree;

		temp = tree->parent;
		tree->parent = pivot_l;
		pivot_l->parent = temp;
		if (temp != NULL)
		{
			if (temp->right == tree)
				temp->right = pivot_l;
			else
				temp->left = pivot_l;
		}
		return (pivot_l);
	}
	return (NULL);
}
