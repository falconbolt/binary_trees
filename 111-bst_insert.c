#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a BST.
 *
 * @tree: Double pointer to the root of the tree.
 * @value: Value to be inserted.
 *
 * Return: Pointer to the new node containing the value, or NULL on failure
 * or the value already exists in the tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *cur;

	new = NULL;
	if (tree == NULL)
		return (NULL);

	cur = *tree;
	if (cur != NULL)
	{
		while (1)
		{
			if (value == cur->n)
				return (NULL);
			if (value < cur->n)
			{
				if (cur->left == NULL)
				{
					new = binary_tree_node(cur, value);
					cur->left = new;
					return (new);
				}
				cur = cur->left;
			}
			else
			{
				if (cur->right == NULL)
				{
					new = binary_tree_node(cur, value);
					cur->right = new;
					return (new);
				}
				cur = cur->right;
			}
		}
	}

	new = binary_tree_node(NULL, value);
	*tree = new;

	return (new);
}
