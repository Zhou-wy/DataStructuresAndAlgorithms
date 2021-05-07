#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 128

typedef int datatype;

typedef struct _Queue
{
    datatype arr[MAX];
    int size;
} Queue;

Queue *QueueInit();
void PushQueue(Queue *queue, datatype data);
void PopQueue(Queue *queue);
datatype BackTopQueue(Queue *queue);
#endif