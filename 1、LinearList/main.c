#include <stdio.h>
#include "LinearList.h"
#include "LinkList.h"

typedef struct _person
{
    /* data */
    char name[64];
    int age;
    int score;
} PERSON;

void MyPrint(void *data)
{
    PERSON *p = (PERSON *)data;
    printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}

int main()
{
    //创建链表
    LinKList *list = Init_LinkList();
    //创建数据
    PERSON P1 = {"aaa", 14, 100};
    PERSON P2 = {"bbb", 13, 90};
    PERSON P3 = {"ccc", 15, 70};
    PERSON P4 = {"ddd", 17, 80};
    PERSON P5 = {"eee", 16, 120};
    //数据入链表
    Insert_LinkList(list, 0, &P1);
    Insert_LinkList(list, 0, &P2);
    Insert_LinkList(list, 0, &P3);
    Insert_LinkList(list, 0, &P4);
    Insert_LinkList(list, 0, &P5);
    //打印
    Printf_LinkList(list, MyPrint);
    FreeSpace_LinkList(list);
    return 0;
}
