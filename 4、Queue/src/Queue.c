#include "Queue.h"

Queue *QueueInit()
{
    Queue *queue = (Queue *)malloc(sizeof(queue));
    for (int i = 0; i < MAX; i++)
    {
        queue->arr[i] = NULL;
    }
    queue->size = 0;
}
void PushQueue(Queue *queue, datatype data)
{
    if (queue == NULL || queue->size == MAX)
    {
        return;
    }
    queue->arr[queue->size] = data;
    queue->size++;
}
void PopQueue(Queue *queue)
{
    if (queue == NULL || queue->size == MAX)
    {
        return;
    }
    for (int i = 0; i < queue->size - 1; i++)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->size--;
}
datatype BackTopQueue(Queue *queue)
{
    if (queue == NULL || queue->size == MAX)
    {
        return;
    }
    return queue->arr[queue->size];
}