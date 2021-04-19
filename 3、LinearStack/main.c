#include <stdio.h>
#include "LinearStack.h"

int main()
{
    LinearStack *stack1 = StackInit();
    stack1 = PushStack(stack1, 1);
    stack1 = PushStack(stack1, 2);
    stack1 = PushStack(stack1, 3);
    stack1 = PushStack(stack1, 4);
    stack1 = PushStack(stack1, 5);

    stack1 = PopStack(stack1);
    stack1 = PopStack(stack1);

    return 0;
}
