#include "binary_trees.h"

void postorder_traverse(const binary_tree_t *node, void (*func)(int));

/**
 * binary_tree_postorder - Perform post-order traversal on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
		postorder_traverse(tree, func);
}

/**
 * postorder_traverse - Recursively travel down the left side first, print left
 * node values first, then sibling, and then parent.
 *
 * @node: Pointer to the current node.
 * @func: Pointer to a function to call for each node.
 */
void postorder_traverse(const binary_tree_t *node, void (*func)(int))
{
	if (node->left != NULL)
		postorder_traverse(node->left, func);

	if (node->right != NULL)
		postorder_traverse(node->right, func);

	func(node->n);
}
