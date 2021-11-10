#include "CircularQueue.h"
void MyCircularQueueInit(MyCircularQueue** QHead)
{
    (*QHead)->a = NULL;
    (*QHead)->size = (*QHead)->capacity = 0;
    (*QHead)->Head = -1;
    (*QHead)->Tail = 0;
}
//创建
MyCircularQueue* myCircularQueueCreate(int k) {
    //用顺序表来写
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
    //因为数组本身下标就会比总数少1，所以就不用k+1来赋值了
    QHead->capacity = k;
    return QHead;
}
//插入
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == (obj->capacity-1))
    {
        return false;
    }
    if (obj->size == -1)
    {//插入第一个节点时
        obj->size++;
        obj->Tail = obj->Head = obj->size;
        obj->a[obj->Tail] = value;
    }
    else
    {//size不满
        obj->size++;
        //让指向尾的节点
        obj->Tail = (obj->Tail + 1) % (obj->capacity);
        obj->a[obj->Tail] = value;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(!myCircularQueueIsEmpty(&obj));
    //只有一个节点
    if (obj->size == 0)
    {
        obj->Head = obj->Tail = -1;
        return true;
    }
    //不止一个节点
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
