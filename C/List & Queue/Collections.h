#if !defined COLLECTIONS_H_
#define COLLECTIONS_H_

struct _node
{
	double val;
	struct _node * prev;
	struct _node * next;
};
typedef struct _node Node;

struct _list
{
	Node * head;
	Node * last;
	unsigned int length;
	double sum;
};
typedef struct _list List;

struct _queue
{
	Node * head;
	Node * last;
	unsigned int length;
};
typedef struct _queue Queue;

/*******List Functions********/

List generateList();
Node * ladd(List * list, double val);
Node * linsert(List * list, Node * node, double val);
Node * lremove(List * list, Node * node);
Node * getHead(List list);
Node * getLast(List list);
Node * getNext(Node * node);
Node * getPrev(Node * node);
double getVal(Node * node);
unsigned int getLength(List list);
double getAvg(List list);
void terminateList(List * list);

/*******Queue Functions*******/

Queue generateQueue();
void enqueue(Queue * queue, double val);
double dequeue(Queue * queue);
unsigned int qGetLength(Queue queue);
double peek(Queue queue);
void terminateQueue(Queue * queue);

#endif