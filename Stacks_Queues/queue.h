#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
    int size;
    int front;
    int rear;
    unsigned capacity;
    int *arr;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = capacity-1;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
}

int isFull(struct Queue* q)
{
    return (q->size == q->capacity);
}

int isEmpty(struct Queue* q)
{
    return (q->size==0);
}

void Enqueue(struct Queue* q, int data)
{
    if(isFull(q))
        return;
    q->rear = (q->rear+1)%(q->capacity);
    q->arr[q->rear] = data;
    q->size += 1;
}

int Dequeue(struct Queue* q)
{
    if(isEmpty(q))
        return INT_MIN;
    int item = q->arr[q->front];
    q->front = (q->front+1)%(q->capacity);
    q->size -= 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}


