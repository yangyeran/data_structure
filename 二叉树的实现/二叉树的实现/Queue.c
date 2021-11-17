#include "Queue.h"
//队列是先进的先出
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//申请节点
QNode* BuyQNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
		exit(-1);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = BuyQNode(data);
	if (q->front == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = q->rear->next;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//队列不为空
	Queue* next = q->front->next;
	free(q->front);
	q->front = next;
	if (q->front == NULL)//如果front为空rear也需要置空不然就产生了野指针
	{
		q->rear == NULL;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	//非空返回0
	if (QueueEmpty(q))
	{
		return 0;
	}
	//有节点
	int count = 0;
	QNode* cur = q->front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
	free(q);
}