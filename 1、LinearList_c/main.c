#include <stdio.h>
#include "LinearList.h"

int main()
{
    //printf("hello world\n");
    ChaLenArray *Array = Init_Array();
    printf("1 array size is %d\n", Array->size);
    printf("2 array cap is %d\n", Array->cap);
    for (int i = 0; i < 30; i++)
    {
        Push_Back_Array(Array, i);
    }
    Printf_Array(Array);
    printf("3 array size is %d\n", Array->size);
    printf("4 array cap is %d\n", Array->cap);

    int pos = Find_Array(Array, 5);
    int value = At_Array(Array, 10);
    printf("pos:%d \n", pos);
    printf("value:%d \n", value);

    RemoveByPos_Array(Array, 5);
    RemoveByValue_Array(Array, 27);
    Printf_Array(Array);
    FreeSpace_Array(Array);
    return 0;
}
