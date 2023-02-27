#include "binary_trees.h"
#include <stdlib.h>

heap_t *reorder_heap(heap_t *node);
heap_t *insert_node(heap_t *parent, int value);
heap_t *find_a_parent(heap_t *node);
queue *enqueue(queue *tail, heap_t *node);
void free_queue(queue *head);

/**
 * heap_insert - Inserts a value into a max binary heap.
 *
 * @root: Double pointer to the root of the max binary heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = find_a_parent(*root);
	new = insert_node(parent, value);
	if (new == NULL)
		return (NULL);
	new = reorder_heap(new);

	return (new);
}

/**
 * find_a_parent - Finds a parent for the new node by using a queue. The first
 * node to not have children will be the parent.
 *
 * @node: Pointer to the root of the current tree.
 * Return: Pointer to the parent of the node.
 */
heap_t *find_a_parent(heap_t *node)
{
	queue *head, *temp, *tail;
	heap_t *parent;

	head = enqueue(NULL, node);
	tail = head;

	while (head != NULL)
	{
		parent = head->cur;
		if (parent->left == NULL || parent->right == NULL)
		{
			free_queue(head);
			head = NULL;
		}
		else
		{
			tail = enqueue(tail, parent->left);
			if (tail == NULL)
			{
				free_queue(head);
				return (NULL);
			}
			tail = enqueue(tail, parent->right);
			if (tail == NULL)
			{
				free_queue(head);
				return (NULL);
			}
			temp = head->next;
			free(head);
			head = temp;
		}
	}

	return (parent);
}

/**
 * free_queue - Frees up memory taken by a queue.
 *
 * @head: The head of the queue.
 */
void free_queue(queue *head)
{
	queue *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * enqueue - Enqueues a node to a queue.
 *
 * @tail: Pointer to the current tail of the queue.
 * @node: Max binary heap node to place into queue.
 *
 * Return: Pointer to the new node in the queue.
 */
queue *enqueue(queue *tail, heap_t *node)
{
	queue *q_node;

	q_node = malloc(sizeof(queue));
	if (q_node == NULL)
		return (NULL);

	if (tail != NULL)
		tail->next = q_node;
	q_node->cur = node;
	q_node->next = NULL;

	return (q_node);
}


/**
 * reorder_heap - Readjusts the heap if heap property is broken.
 *
 * @node: Current node that is the newly created node.
 *
 * Return: Pointer to the new node.
 */
heap_t *reorder_heap(heap_t *node)
{
	heap_t *parent;
	int temp;

	parent = node->parent;

	while (parent != NULL && node->n > parent->n)
	{
		temp = parent->n;
		parent->n = node->n;
		node->n = temp;
		node = parent;
		parent = node->parent;
	}

	return (node);
}

/**
 * insert_node - Inserts a node into the max binary heap.
 *
 * @parent: The parent of the inserted node.
 * @value: The value to store in the inserted node.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *insert_node(heap_t *parent, int value)
{
	heap_t *node;

	node = binary_tree_node(parent, value);
	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}


