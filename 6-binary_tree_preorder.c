#include "binary_trees.h"

void preorder_traverse(const binary_tree_t *node, void (*func)(int));

/**
 * binary_tree_preorder - Perform pre-order traversal on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
		preorder_traverse(tree, func);
}

/**
 * preorder_traverse - Recursively travel down the left side of a binary tree.
 *
 * @node: Pointer to the current node.
 * @func: Pointer to a function to call for each node.
 */
void preorder_traverse(const binary_tree_t *node, void (*func)(int))
{
	func(node->n);

	if (node->left != NULL)
		preorder_traverse(node->left, func);

	if (node->right != NULL)
		preorder_traverse(node->right, func);
}
