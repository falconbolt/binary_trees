#include "binary_trees.h"

char traverse(const binary_tree_t *cur, const binary_tree_t *second);

/**
 * binary_trees_ancestor - Find the lowest commom ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor or NULL if there is none.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *cur, *prev;
	char found;

	found = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);

	if (traverse(first->left, second) == 1)
		return ((binary_tree_t *) first);
	if (traverse(first->right, second) == 1)
		return ((binary_tree_t *) first);

	cur = first->parent;
	prev = (binary_tree_t *) first;
	while (cur != NULL)
	{
		if (cur == second)
			return (cur);
		if (cur->left == prev)
			found = traverse(cur->right, second);
		else
			found = traverse(cur->left, second);

		if (found == 1)
			return (cur);

		prev = cur;
		cur = cur->parent;
	}

	return (NULL);
}

/**
 * traverse - Traverses the binary tree using DFS.
 *
 * @cur: Pointer to the current binary tree to search for.
 * @second: Pointer to the node to look for.
 *
 * Return: 1 if second is found, 0 otherwise.
 */
char traverse(const binary_tree_t *cur, const binary_tree_t *second)
{
	if (cur == NULL)
		return (0);

	if (cur == second)
		return (1);

	if (traverse(cur->left, second) == 1)
		return (1);

	if (traverse(cur->right, second) == 1)
		return (1);

	return (0);
}
