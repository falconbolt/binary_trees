#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 *
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: NUll if node is NULL or parent is NULL or node has no sibling. Other
 * wise return the pointer to the sibling node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_p;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);
	grand_p = parent->parent;
	if (grand_p == NULL)
		return (NULL);

	if (grand_p->left == parent)
		return (grand_p->right);
	else
		return (grand_p->left);
}
