#include "binary_trees.h"

#define LIMIT 100

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Tree nodes only limited to 100 else failure.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *queue[LIMIT];
	const binary_tree_t *temp;
	int front, rear;
	int null_flag = 0;

	if (tree == NULL)
		return (0);

	front = rear = -1;
	queue[++rear] = tree;

	while (front < rear)
	{
		temp = queue[++front];

		if (temp == NULL && null_flag == 0)
		{
			null_flag = 1;
		}
		else if (temp != NULL && null_flag == 1)
		{
			return (0);
		}
		else
		{
			if (temp != NULL)
			{
				queue[++rear] = temp->left;
				queue[++rear] = temp->right;
			}
		}
	}
	return (1);
}
