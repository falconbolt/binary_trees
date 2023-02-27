#include "binary_trees.h"
#include <limits.h>

char check_bst(const binary_tree_t *root, int min, int max);
char check_height(const binary_tree_t *root, int *height);

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree. AVL trees are
 * also BST trees. The difference between the heights of left and right
 * subtress cannot be more than one.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);
	if (check_bst(tree, INT_MIN, INT_MAX) != 1)
		return (0);
	if (check_height(tree, &height) != 1)
		return (0);

	return (1);
}

/**
 * check_bst - Traverse the tree to check if it is a BST.
 *
 * @root: Pointer to the root of the tree to check.
 * @min: The min value the node must be greater than.
 * @max: The max value the node must be less than.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
char check_bst(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);

	if (root->n < min || root->n > max)
		return (0);

	return (check_bst(root->left, min, root->n - 1) &&
			check_bst(root->right, root->n + 1, max));
}

/**
 * check_height - Traverse the tree to check if the heights of the subtrees
 * do not differ by more than one.
 *
 * @root: Pointer to the root of the tree to check.
 * @height: Height of the tree currently.
 *
 * Return: 1 if the heights of the tree do not differ by more than one, 0
 * otherwise.
 */
char check_height(const binary_tree_t *root, int *height)
{
	int left_h, right_h, diff;

	if (root == NULL)
		return (1);

	(*height)++;
	left_h = *height;
	right_h = *height;

	if (check_height(root->left, &left_h) != 1 ||
			check_height(root->right, &right_h) != 1)
		return (0);

	if (left_h < right_h)
		(*height) = right_h;
	else
		(*height) = left_h;

	diff = left_h - right_h;

	if (diff < -1 || diff > 1)
		return (0);
	else
		return (1);
}
