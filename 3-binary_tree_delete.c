#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes a binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *cur, *nxt;

	cur = tree;
	while (cur != NULL)
	{
		nxt = cur->left;
		cur->left = NULL;
		if (nxt == NULL)
		{
			nxt = cur->right;
			cur->right = NULL;
		}
		if (nxt == NULL)
		{
			nxt = cur->parent;
			cur->parent = NULL;
			cur->left = NULL;
			cur->right = NULL;
			free(cur);
		}
		cur = nxt;
	}
}
