#include <stdio.h>
#include "Queue.h"

int main()
{

    Queue *queue = QueueInit();
    PushQueue(queue, 1);
    PushQueue(queue, 2);
    PushQueue(queue, 3);
    PushQueue(queue, 4);
    PushQueue(queue, 5);

    while (queue->size > 0)
    {
        printf("队列数据：", BackTopQueue(queue));
        PopQueue(queue);
    };
    return 0;
}
