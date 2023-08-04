#include "binary_trees.h"

bst_t *bst_delete(const bst_t *root, bst_t *node);
bst_t *bst_node_search(const bst_t *root, bst_t *tree, int value);
bst_t *inorder_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/**
 * bst_node_search - Searches for a node/value
 *						to remove in a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * @tree:  A pointer to the current node in the BST.
 * @value: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the root node after deletion.
 */
bst_t *bst_node_search(const bst_t *root, bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return (bst_delete(root, tree));

	return (tree->n > value
			? bst_node_search(root, tree->left, value) :
			bst_node_search(root, tree->right, value));
}

/**
 * inorder_successor - Returns the smallest value of a binary search tree.
 * @node: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(const bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* one right children or none */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : (bst_t *)root);
	}

	/* one left children or none */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->right == node)
			parent->right = node->left;
		else if (parent != NULL)
			parent->left = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : (bst_t *)root);
	}

	/* two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_node_search(root, root, value));
}
