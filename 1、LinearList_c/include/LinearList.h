#ifndef LINEARLIST_H
#define LISTARLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct changeLength1D
{
    /* data */
    int *pAddr;
    int size;
    int cap;
} ChaLenArray;
ChaLenArray *Init_Array();                             //初始化一个动态数组
void Push_Back_Array(ChaLenArray *arr, int value);     //尾部插入一个数据
void RemoveByPos_Array(ChaLenArray *arr, int pos);     //通过位置删除一个元素
void RemoveByValue_Array(ChaLenArray *arr, int value); //通过值删除一个元素
int Find_Array(ChaLenArray *arr, int value);           //找到一个元素
void Printf_Array(ChaLenArray *arr);                   //打印
void FreeSpace_Array(ChaLenArray *arr);                //释放一个动态数组内存空间
void Clear_Array(ChaLenArray *arr);
int Size_Array(ChaLenArray *arr);
int At_Array(ChaLenArray *arr, int pos);

#endif