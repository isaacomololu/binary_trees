#include "binary_trees.h"

/**
 * create_node - Creates a new queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
queue_t *create_node(binary_tree_t  *node)
{
	queue_t *new_node;

	new_node = malloc(sizeof(queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * queue_push - Processes given binary tree node and
 *             pushes its children into a levelorder queue_t queue.
 * @node: The binary tree node to print and push.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void queue_push(binary_tree_t *node, queue_t **tail, void (*func)(int))
{
	binary_tree_t *temp = node;
	queue_t *new_node;

	func(node->n);
	if (temp->left)
	{
		new_node = create_node(temp->left);
		(*tail)->next = new_node;
		*tail = new_node;
	}

	if (temp->right)
	{
		new_node = create_node(temp->right);
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *front = NULL, *tail = NULL, *temp = NULL;

	if (tree && func)
	{
		front = tail = create_node((binary_tree_t *)tree);
		if (!front)
			return;

		while (front != NULL)
		{
			queue_push(front->node, &tail, func);
			temp = front;
			front = front->next;
			free(temp);
		}
	}
}
