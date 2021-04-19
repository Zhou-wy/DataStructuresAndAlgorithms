#include "LinearList.h"
/*
ChaLenArray *Expand_Capacity(ChaLenArray *old_arr)
{
    if (old_arr == NULL)
        return NULL;
    ChaLenArray *New_arr;
    New_arr->cap = (int *)malloc(sizeof(int) * old_arr->cap * 2);
    memcpy(New_arr->pAddr, old_arr->pAddr, old_arr->cap * sizeof(int));
    New_arr->size = old_arr->size;
    free(old_arr->pAddr);
    return New_arr;
}
*/
ChaLenArray *Init_Array() //初始化一个动态数组
{
    ChaLenArray *NewArray = (ChaLenArray *)malloc(sizeof(ChaLenArray));
    NewArray->size = 0;
    NewArray->cap = 20;
    NewArray->pAddr = (int *)malloc(sizeof(int) * NewArray->cap);
    return NewArray;
}
void Push_Back_Array(ChaLenArray *arr, int value) //尾部插入一个数据
{
    if (arr == NULL)
        return;
    if (arr->size >= arr->cap)
    {
        //ChaLenArray *arr = Expand_Capacity(arr);
        int *Newspce = (int *)malloc(arr->cap * 2 * sizeof(int));
        memcpy(Newspce, arr->pAddr, arr->cap * sizeof(int));
        free(arr->pAddr);
        arr->cap = arr->cap * 2;
        arr->pAddr = Newspce;
    }
    arr->pAddr[arr->size] = value;
    arr->size++;
}

void RemoveByPos_Array(ChaLenArray *arr, int pos) //通过位置删除一个元素
{
    if (arr == NULL)
        return;
    if (pos < 0 || pos >= arr->size)
        return;
    for (int i = pos; i < arr->size - 1; i++)
    {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
    arr->size--;
}
void RemoveByValue_Array(ChaLenArray *arr, int value) //通过值删除一个元素
{
    if (arr == NULL)
        return;
    int pos = Find_Array(arr, value);
    RemoveByPos_Array(arr, pos);
}
int Find_Array(ChaLenArray *arr, int value) //找到一个元素
{
    if (arr == NULL)
        return -1;
    int pos = -1;
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->pAddr[i] == value)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
void Printf_Array(ChaLenArray *arr) //打印
{
    if (arr == NULL)
        return;
    for (int i = 0; i < arr->size; i++)
    {
        /* code */
        printf("%d ", arr->pAddr[i]);
    }
    printf("\n");
}
void FreeSpace_Array(ChaLenArray *arr) //释放一个动态数组内存空间
{
    if (arr == NULL)
        return;
    if (arr->pAddr != NULL)
    {
        /* code */
        free(arr->pAddr);
    }
    free(arr);
}
void Clear_Array(ChaLenArray *arr)
{
    if (arr == NULL)
        return;
    arr->size = 0;
}
int Size_Array(ChaLenArray *arr)
{
    if (arr == NULL)
        return -1;
    return arr->size;
}
int At_Array(ChaLenArray *arr, int pos)
{
    if (arr == NULL)
        return -1;
    return arr->pAddr[pos];
}