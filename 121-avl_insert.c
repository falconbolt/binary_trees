#include "binary_trees.h"

avl_t *insert_in_branch(avl_t *cur, int value);
avl_t *find_imbalance(avl_t *cur, int *height);
avl_t *fix_imbalance(avl_t *imbal);

/**
 * avl_insert - Inserts a value in an AVL tree.
 *
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: the value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL upon failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *imbalanced, *imbal_fixed;
	int height = 0;

	new = NULL;
	imbalanced = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree != NULL)
	{
		new = insert_in_branch(*tree, value);
		imbalanced = find_imbalance(*tree, &height);
		if (imbalanced != NULL)
			imbal_fixed = fix_imbalance(imbalanced);
		if (imbalanced == *tree)
			*tree = imbal_fixed;
	}
	else
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
	}

	return (new);
}

/**
 * insert_in_branch - Insert the value into the sub-branch of root.
 *
 * @cur: Child of the root.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL upon failure.
 */
avl_t *insert_in_branch(avl_t *cur, int value)
{
	avl_t *new;

	new = NULL;
	while (new == NULL)
	{
		if (value == cur->n)
			return (NULL);
		if (value < cur->n)
		{
			if (cur->left == NULL)
			{
				new = binary_tree_node(cur, value);
				cur->left = new;
			}
			cur = cur->left;
		}
		else
		{
			if (cur->right == NULL)
			{
				new = binary_tree_node(cur, value);
				cur->right = new;
			}
			cur = cur->right;
		}
	}

	return (new);
}

/**
 * find_imbalance - Search for imbalance within an AVL tree if it exists.
 *
 * @cur: Pointer to the current node within AVL tree.
 * @height: Pointer to counter for current height of the tree.
 *
 * Return: Pointer to the node with the imbalance, NULL if there is no
 * imbalance.
 */
avl_t *find_imbalance(avl_t *cur, int *height)
{
	int left_h, right_h, diff;
	avl_t *imbalance;

	imbalance = NULL;

	if (cur == NULL)
		return (NULL);

	(*height)++;
	left_h = *height;
	right_h = *height;

	imbalance = find_imbalance(cur->left, &left_h);
	if (imbalance != NULL)
		return (imbalance);

	imbalance = find_imbalance(cur->right, &right_h);
	if (imbalance != NULL)
		return (imbalance);

	if (left_h < right_h)
		(*height) = right_h;
	else
		(*height) = left_h;

	diff = left_h - right_h;
	if (diff < -1 || diff > 1)
		return (cur);
	else
		return (NULL);
}

/**
 * fix_imbalance - Correct the imbalance within the subtree.
 *
 * @imbal: Pointer to the root of the imbalanced tree.
 *
 * Return: New root after rotation(s).
 */
avl_t *fix_imbalance(avl_t *imbal)
{
	int bal_fac, child_bal_fac;
	avl_t *new_root;

	bal_fac = binary_tree_balance(imbal);
	if (bal_fac > 0)
	{
		child_bal_fac = binary_tree_balance(imbal->left);
		if (child_bal_fac > 0)
		{
			new_root = binary_tree_rotate_right(imbal);
		}
		else
		{
			new_root = binary_tree_rotate_left(imbal->left);
			new_root = binary_tree_rotate_right(imbal);
		}
	}
	else
	{
		child_bal_fac = binary_tree_balance(imbal->right);
		if (child_bal_fac > 0)
		{
			new_root = binary_tree_rotate_right(imbal->right);
			new_root = binary_tree_rotate_left(imbal);
		}
		else
		{
			new_root = binary_tree_rotate_left(imbal);
		}
	}

	return (new_root);
}
