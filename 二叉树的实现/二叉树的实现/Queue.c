#include "Queue.h"
//�������Ƚ����ȳ�
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//����ڵ�
QNode* BuyQNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
		exit(-1);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
// ��β����� 
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
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//���в�Ϊ��
	Queue* next = q->front->next;
	free(q->front);
	q->front = next;
	if (q->front == NULL)//���frontΪ��rearҲ��Ҫ�ÿղ�Ȼ�Ͳ�����Ұָ��
	{
		q->rear == NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	//�ǿշ���0
	if (QueueEmpty(q))
	{
		return 0;
	}
	//�нڵ�
	int count = 0;
	QNode* cur = q->front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
// ���ٶ��� 
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