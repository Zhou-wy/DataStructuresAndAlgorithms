#include "LinearStack.h"

LinearStack *StackInit()
{
    LinearStack *stack = (LinearStack *)malloc(sizeof(LinearStack));
    for (int i = 0; i < MAX_SIZE; i++)
        stack->arr[i] = 0;
    stack->size = 0;
    return stack;
}

LinearStack *PushStack(LinearStack *stack, dataType data)
{
    stack->arr[stack->size] = data;
    printf("数据:%d压入栈，位置为:%d \n", stack->arr[stack->size], stack->size);
    stack->size++;
    return stack;
}
LinearStack *PopStack(LinearStack *stack)
{

    printf("数据:%d出栈", stack->arr[stack->size]);
    stack->arr[stack->size] = 0;
    stack->size--;
    printf("剩余栈长为：%d \n", stack->size);
    return stack;
}
dataType TopOfStack(LinearStack *stack)
{
    return stack->arr[stack->size];
}
