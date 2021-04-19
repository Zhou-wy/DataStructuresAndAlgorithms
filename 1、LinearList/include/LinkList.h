#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LINKNODE
{
    void *data; //指向任何数据指针
    struct LINKNODE *next;
} LinkNode;

typedef struct LINKLIST
{
    LinkNode *head;
    int size;
} LinKList;

typedef void (*PRINTFLINKNODE)(void *);
LinKList *Init_LinkList();
void Insert_LinkList(LinKList *list, int pos, void *data);
void RemoveByBos_linkList(LinKList *list, int pos);
int Size_linkList(LinKList *list);
void *Front_LinkList(LinKList *list);
void FreeSpace_LinkList(LinKList *list);
int Find_LinkList(LinKList *list, void *data);
void Printf_LinkList(LinKList *list, PRINTFLINKNODE print);

#endif
