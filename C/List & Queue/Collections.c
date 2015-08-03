#include <stdio.h>
#include <stdlib.h>
#include "Collections.h"

/******************************
********List Functions*********
******************************/

/*Generate a new empty list and returns it. */
List generateList()
{
	List list;
	list.head = list.last = NULL;
	list.length = 0;
	list.sum = 0;

	return list;
}

/*Add new item to the end of the list. returns a pointer to the newly added item */
Node * ladd(List * list, double val)
{
        // T: check list pointer is not null
	if (list->head == NULL)
	{
		list->head = (Node *)malloc(sizeof(Node)); // T: On failure malloc returns null - handle it
		list->head->prev = NULL;
		list->head->val = val;
		list->last = list->head;
	}
	else
	{
		list->last->next = (Node *)malloc(sizeof(Node)); // T: On failure malloc returns null - handle it
		list->last->next->prev = list->last;
		list->last->next->val = val;
		list->last = list->last->next;
	}
	list->last->next = NULL;
	++list->length;
	list->sum += val;
	return list->last;
}

/*Insert an item to the list before the specific node passed to the function. returns a pointer to the newly added item */
Node * linsert(List * list, Node * node, double val)
{
        // T: check list pointer is not null
	if (node == NULL)
	{
		return ladd(list, val);
	}
	Node * nitem = (Node *)malloc(sizeof(Node)); // T: On failure malloc returns null - handle it
	if (node == list->head)
	{
		nitem->val = val;
		nitem->prev = NULL;
		nitem->next = list->head;
		list->head = nitem;
		list->head->next->prev = list->head; 
	}
	else
	{
		nitem->val = val;
		nitem->prev = node->prev;
		nitem->prev->next = nitem;
		nitem->next = node;
		node->prev = nitem;
	}
	++list->length;
	list->sum += val;
	return nitem;
}

/*Remove an item from the list, given a pointer to it. */
Node * lremove(List * list, Node * node)
{
        // T: check list pointer is not null
	if (node == list->head)
	{
		if (node->next == NULL)
		{
			list->head = NULL;
		}
		else
		{
			list->head = node->next;
			list->head->prev = NULL;
		}
	}
	else if (node == list->last)
	{
		list->last = node->prev;
		list->last->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	list->sum -= node->val;
	free(node);
	--list->length;
	return node->next; // T: bad use of node after free
}

/*Get the head of a list (pointer). */
Node * getHead(List list)
{
	return list.head;
}

/*Get the last item in a list (pointer). */
Node * getLast(List list)
{
	return list.last;
}

/*Get next item in a list (Given a pointer to an item). */
Node * getNext(Node * node)
{
	if (node == NULL)
		return NULL;
	return node->next;
}

/*Get previous item in a list (Given a pointer to an item). */
Node * getPrev(Node * node)
{
	if (node == NULL)
		return NULL;
	return node->prev;
}

/*Get value of an item in a list. */
double getVal(Node * node)
{
	if (node != NULL)
		return node->val;
	printf("Error: can not return value of NULL node, returned 0 instead. "); // T: printf without endline? It won`t flushed to stdout
	return 0;
}

/*Get length of a list */
unsigned int lGetLength(List list)
{
	return list.length;
}

/*Get average of list items */
double getAvg(List list)
{
	return (list.sum / list.length);
}

/*Clear a list */
void terminateList(List * list)
{
        // T: check list pointer is not null
	Node * cur_node = list->head;
	while (cur_node != NULL)
	{
		Node * temp = cur_node->next;
		free(cur_node);
		cur_node = temp;
	}
	list->head = list->last = NULL;
	list->length = 0;
	list->sum = 0;
}

/******************************
********Queue Functions********
******************************/

/*Generate a new empty queue and returns it. */
Queue generateQueue()
{
	Queue queue;
	queue.head = queue.last = NULL;
	queue.length = 0;

	return queue;
}

/*Enqueue an item to the end of the queue */
void enqueue(Queue * queue, double val)
{
        // T: check queue pointer is not null
	if (queue->head == NULL)
	{
		queue->head = (Node *)malloc(sizeof(Node)); // T: On failure malloc returns null - handle it
		queue->head->prev = NULL;
		queue->head->val = val;
		queue->last = queue->head;
	}
	else
	{
		queue->last->next = (Node *)malloc(sizeof(Node)); // T: On failure malloc returns null - handle it
		queue->last->next->prev = queue->last;
		queue->last->next->val = val;
		queue->last = queue->last->next;
	}
	queue->last->next = NULL;
	++queue->length;
}

/*Dequeue the item at the head of the queue and return its value */
double dequeue(Queue * queue)
{
        // T: check queue pointer is not null
	Node * to_remove = queue->head;
	double val = to_remove->val; // T: what if the queue is empty?
	queue->head = queue->head->next;
	if (queue->head != NULL)
	{
		free(queue->head->prev);
		queue->head->prev = NULL;
	}
	else
	{
		free(to_remove); // T: both free calls fre the same memory, y not write it only one?
	}
        // T: what if there was only one node? what about queue->last?
	--queue->length;
	return val;
}

/*Returns the length of a queue */
unsigned int qGetLength(Queue queue)
{
	return queue.length;
}

/*Returns the value of the item in the head of the queue without removing it */
double peek(Queue queue)
{
	return queue.head->val;
}

/*Clear a queue */
void terminateQueue(Queue * queue)
{
        // T: check queue pointer is not null
	while (queue->length != 0)
	{
		dequeue(queue);
	}
}
