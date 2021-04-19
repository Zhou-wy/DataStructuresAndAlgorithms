#ifndef _LINEARSTACK_H
#define _LINEARSTACK_H
#define MAX_SIZE 128
#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct _LinearStack
{
    dataType arr[MAX_SIZE];
    int size;
} LinearStack;

LinearStack *StackInit();
LinearStack *PushStack(LinearStack *stack, dataType data);
LinearStack *PopStack(LinearStack *stack);
int TopOfStack(LinearStack *stack);

#endif