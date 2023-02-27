#include "binary_trees.h"

/**
 * traverse - Traverse the binary tree for the valid level to print.
 *
 * @node: Pointer to the root node of the current tree.
 * @func: Pointer to the function to call for each node.
 * @height: The current height of the tree.
 * @target: The target level to print the tree.
 *
 * Return: 1 if there was a node on the target level, 0 otherwise.
 */
char traverse(binary_tree_t *node, void (*func)(int),
		size_t height, size_t target);

/**
 * binary_tree_levelorder - Performs "breadth-first" traversal.
 *
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, target;

	height = 0;
	target = 0;

	if (tree == NULL || func == NULL)
		return;

	while (traverse((binary_tree_t *)tree, func, height, target) == 1)
		target++;
}

/**
 * traverse - Traverse the binary tree for the valid level to print.
 *
 * @node: Pointer to the root node of the current tree.
 * @func: Pointer to the function to call for each node.
 * @height: The current height of the tree.
 * @target: The target level to print the tree.
 *
 * Return: 1 if there was a node on the target level, 0 otherwise.
 */
char traverse(binary_tree_t *node, void (*func)(int),
		size_t height, size_t target)
{
	char left, right;

	if (node == NULL)
		return (0);

	if (height == target)
	{
		func(node->n);
		return (1);
	}
	else
	{
		left = traverse(node->left, func, height + 1, target);
		right = traverse(node->right, func, height + 1, target);
		return (left || right);
	}
}
