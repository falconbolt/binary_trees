#include "binary_trees.h"
#include <stdlib.h>

bst_t *successor(bst_t *node);
bst_t *bst_replace(bst_t *parent, bst_t *node, bst_t *suc);

/**
 * bst_remove - Removes a value from the BST if it exists.
 *
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *parent, *replacement;

	node = bst_search(root, value);
	if (node == NULL)
		return (NULL);

	parent = node->parent;

	if (node->left == NULL && node->right == NULL)
		replacement = bst_replace(parent, node, NULL);
	else if (node->left != NULL && node->right != NULL)
		replacement = bst_replace(parent, node, successor(node->right));
	else if (node->left != NULL)
		replacement = bst_replace(parent, node, node->left);
	else if (node->right != NULL)
		replacement = bst_replace(parent, node, node->right);

	if (root == node)
		root = replacement;

	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	free(node);
	return (root);
}

/**
 * successor - Searches for the first in-order successor to the node that is
 * to be deleted.
 *
 * @node: Pointer to the current node;
 *
 * Return: The successor.
 */
bst_t *successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;

	return (node);
}

/**
 * bst_replace - Replaces the node to be deleted with a successor.
 *
 * @parent: Parent of the node to be deleted.
 * @node: The node to be deleted.
 * @suc: The successor of the node to be deleted.
 *
 * Return: The sucessor of the node to be deleted.
 */
bst_t *bst_replace(bst_t *parent, bst_t *node, bst_t *suc)
{
	bst_t *r_child;

	if (parent != NULL)
	{
		if (parent->left == node)
			parent->left = suc;
		else
			parent->right = suc;
	}
	if (suc != NULL)
	{
		if (node->left != NULL && node->right != NULL)
		{
			if (node->left != suc)
			{
				suc->left = node->left;
				node->left->parent = suc;
			}
			if (node->right != suc)
			{
				r_child = suc;
				while (r_child->right != NULL)
					r_child = r_child->right;
				r_child->right = node->right;
				node->right->parent = r_child;
			}

		}
		if (suc->parent != NULL)
		{
			if (suc->parent->left == suc)
				suc->parent->left = NULL;
			else
				suc->parent->right = NULL;
		}
		suc->parent = parent;
	}

	return (suc);
}

/**
 * bst_search - Searches for a value in a BST.
 *
 * @tree: Pointer to the root node of the BST.
 * @value: Value to search for.
 *
 * Return: Pointer to the node containing the value, otherwise NULL if not
 * found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *cur;

	if (tree == NULL)
		return (NULL);

	cur = (bst_t *) tree;

	while (cur != NULL)
	{
		if (cur->n == value)
			return (cur);
		if (value < cur->n)
			cur = cur->left;
		else
			cur = cur->right;
	}

	return (NULL);
}
