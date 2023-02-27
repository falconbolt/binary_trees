#include "binary_trees.h"
#include <stdlib.h>

void reorder_heap_r(heap_t *node);
heap_t *find_last(heap_t *node);
queue *enqueue_r(queue *tail, heap_t *node);
void free_queue_r(queue *head);

/**
 * heap_extract - Remove the root node and return its' n value..
 *
 * @root: Double pointer to the root of the max binary heap.
 *
 * Return: The extracted value, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int val;

	if (root == NULL || *root == NULL)
		return (0);

	last = find_last(*root);
	if (last == NULL)
		return (0);

	val = (*root)->n;
	if (last == *root)
	{
		free(last);
		*root = NULL;
		return (val);
	}

	(*root)->n = last->n;
	if (last->parent != NULL)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	free(last);
	reorder_heap_r(*root);

	return (val);
}

/**
 * find_last - Finds the last level-order node of the heap.
 *
 * @node: Pointer to the root of the current tree.
 *
 * Return: Pointer to the last level-order node of the heap.
 */
heap_t *find_last(heap_t *node)
{
	queue *head, *next, *tail;
	heap_t *last;

	head = enqueue_r(NULL, node);
	tail = head;
	next = head;

	do {
		head = next;
		last = head->cur;
		if (last->left != NULL)
		{
			tail = enqueue_r(tail, last->left);
			if (tail == NULL)
			{
				free_queue_r(head);
				return (NULL);
			}
		}
		if (last->right != NULL)
		{
			tail = enqueue_r(tail, last->right);
			if (tail == NULL)
			{
				free_queue_r(head);
				return (NULL);
			}
		}
		next = head->next;
		free(head);
	} while (next != NULL);
	return (last);
}

/**
 * free_queue_r - Frees up memory taken by a queue.
 *
 * @head: The head of the queue.
 */
void free_queue_r(queue *head)
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
 * enqueue_r - Enqueues a node to a queue.
 *
 * @tail: Pointer to the current tail of the queue.
 * @node: Max binary heap node to place into queue.
 *
 * Return: Pointer to the new node in the queue.
 */
queue *enqueue_r(queue *tail, heap_t *node)
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
 * reorder_heap_r - Readjusts the heap if heap property is broken.
 *
 * @node: The new root of the tree.
 */
void reorder_heap_r(heap_t *node)
{
	heap_t *swap;
	int temp;

	swap = NULL;

	while (swap != node)
	{
		swap = node;
		if (node->left != NULL && node->right != NULL)
		{
			if (node->left->n > node->right->n)
			{
				if (node->left->n > node->n)
					swap = node->left;
			}
			else
			{
				if (node->right->n > node->n)
					swap = node->right;
			}
		}
		else if (node->left != NULL)
		{
			if (node->left->n > node->n)
				swap = node->left;
		}
		else if (node->right != NULL)
		{
			if (node->right->n > node->n)
				swap = node->right;
		}
		if (swap != node)
		{
			temp = swap->n;
			swap->n = node->n;
			node->n = temp;
			node = swap;
			swap = NULL;
		}
	}
}
