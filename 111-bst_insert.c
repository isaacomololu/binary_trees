#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = *tree, *head = NULL;
	bst_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	while (temp)
	{
		head = temp;
		if (value > temp->n)
			temp = temp->right;
		else if (temp->n > value)
			temp = temp->left;
		else if (value == temp->n)
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (head == NULL)
		head = new_node;
	else if (head->n > value)
	{
		head->left = new_node;
	}
	else
	{
		head->right = new_node;
	}
		new_node->parent = head;

	return (new_node);
}
