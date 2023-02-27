#include "binary_trees.h"

char traverse(const binary_tree_t *node);

/**
 * binary_tree_is_full - Check if a binary tree is full.
 *
 * @tree: Pointer to the root node of a tree.
 *
 * Return: 1 if the binary tree is full, 0 otherwise. If tree is NULL return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return ((int) traverse(tree));
}

/**
 * traverse - Recursively travel down a binary tree starting with the left
 * branch.
 *
 * @node: Pointer to the current node.
 *
 * Return: 1 if it is a leaf node or the node is full, 0 otherwise.
 */
char traverse(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/* ^ means XOR */
	if ((node->left == NULL) ^ (node->right == NULL))
		return (0);

	if (traverse(node->left) ^ traverse(node->right))
		return (0);
	else
		return (1);
}
