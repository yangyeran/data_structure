#include "CircularQueue.h"
void MyCircularQueueInit(MyCircularQueue** QHead)
{
    (*QHead)->a = NULL;
    (*QHead)->size = (*QHead)->capacity = 0;
    (*QHead)->Head = -1;
    (*QHead)->Tail = 0;
}
//����
MyCircularQueue* myCircularQueueCreate(int k) {
    //��˳�����д
    MyCircularQueue* QHead = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    MyCircularQueueInit(&QHead);
    QDataType* temp = (QDataType*)malloc(sizeof(QDataType) * (k + 1));
    if (temp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QHead->a = temp;
    QHead->size = -1;
    //��Ϊ���鱾���±�ͻ��������1�����ԾͲ���k+1����ֵ��
    QHead->capacity = k;
    return QHead;
}
//����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == (obj->capacity-1))
    {
        return false;
    }
    if (obj->size == -1)
    {//�����һ���ڵ�ʱ
        obj->size++;
        obj->Tail = obj->Head = obj->size;
        obj->a[obj->Tail] = value;
    }
    else
    {//size����
        obj->size++;
        //��ָ��β�Ľڵ�
        obj->Tail = (obj->Tail + 1) % (obj->capacity);
        obj->a[obj->Tail] = value;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(!myCircularQueueIsEmpty(&obj));
    //ֻ��һ���ڵ�
    if (obj->size == 0)
    {
        obj->Head = obj->Tail = -1;
        return true;
    }
    //��ֹһ���ڵ�
    obj->Head = (obj->Head + 1) % (obj->capacity);
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(!myCircularQueueIsEmpty(&obj));
    return obj->a[obj->Head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(!myCircularQueueIsEmpty(&obj));
    return obj->a[obj->Tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == -1 ? true : false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->capacity - 1)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->size = obj->capacity = 0;
    obj->Head = obj->Tail = 0;
    free(obj);
}
