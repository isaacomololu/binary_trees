#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	unsigned int i;

	if (array == NULL)
		return (NULL);

	root = binary_tree_node(NULL, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
