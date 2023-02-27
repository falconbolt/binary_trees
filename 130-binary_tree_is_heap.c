#include "binary_trees.h"

char traverse(binary_tree_t *node, size_t idx, size_t max_idx);
char is_max(binary_tree_t *root);
size_t get_size(const binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Check if a binary tree is a max binary heap. Heap
 * trees are complete trees where every root value is the max within the tree.
 *
 * @tree: Pointer to the tree to check.
 *
 * Return: 1 if the tree is a max binary heap tree, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_complete((binary_tree_t *) tree) != 1)
		return (0);

	return (is_max((binary_tree_t *) tree));
}

/**
 * is_max - Checks if the root is the max value between its' children.
 *
 * @root: Pointer to the root node.
 *
 * Return: 1 if the root node is the max within the tree, 0 otherwise.
 */
char is_max(binary_tree_t *root)
{
	char l, r;

	if (root == NULL)
		return (1);

	l = is_max(root->left);
	r = is_max(root->right);

	if (root->left != NULL)
	{
		if (root->n < root->left->n)
			return (0);
	}

	if (root->right != NULL)
	{
		if (root->n < root->right->n)
			return (0);
	}

	return (l && r);
}


/**
 * binary_tree_is_complete - Check if the binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = 0;

	size = get_size(tree);
	return (traverse((binary_tree_t *)tree, 0, size - 1));
}

/**
 * traverse - Traverse the binary tree for the valid level to print.
 *
 * @node: Pointer to the root node of the current tree.
 * @idx: The index of the current node.
 * @max_idx: The last index of the tree in array form.
 *
 * Return: 1 if there was a node on the target level, -1 otherwise.
 */
char traverse(binary_tree_t *node, size_t idx, size_t max_idx)
{
	if (node == NULL)
	{
		if (idx <= max_idx)
			return (0);
		return (1);
	}

	return (traverse(node->left, 2 * idx + 1, max_idx) &&
			traverse(node->right, 2 * idx + 2, max_idx));
}


/**
 * get_size - Recursively travel down the left side of a binary tree first.
 *
 * @node: Pointer to the current node.
 *
 * Return: The size of the tree.
 */
size_t get_size(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + get_size(node->left) + get_size(node->right));
}
