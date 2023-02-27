#include "binary_trees.h"

void inorder_traverse(const binary_tree_t *node, void (*func)(int));

/**
 * binary_tree_inorder - Perform in-order traversal on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
		inorder_traverse(tree, func);
}

/**
 * inorder_traverse - Recursively travel down the left side first, print left
 * node values first, then parent, then sibling.
 *
 * @node: Pointer to the current node.
 * @func: Pointer to a function to call for each node.
 */
void inorder_traverse(const binary_tree_t *node, void (*func)(int))
{
	if (node->left != NULL)
		inorder_traverse(node->left, func);

	func(node->n);

	if (node->right != NULL)
		inorder_traverse(node->right, func);
}
