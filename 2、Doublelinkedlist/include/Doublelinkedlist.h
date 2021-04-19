#ifndef _KERNELLIST_H
#define _KERNELLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int NodeDataType;
typedef struct _DoublelinkedNode
{
    struct _DoublelinkedNOde *prior; //指向直接前趋
    NodeDataType data;
    struct _DoublelinkedNode *next; //指向直接后继
} DoubLinkNode;

DoubLinkNode *DoubListInit();
void PrintfList(DoubLinkNode *list);
DoubLinkNode *InsertNode(DoubLinkNode *list, NodeDataType data, int pos);
DoubLinkNode *DeleteNodeByData(DoubLinkNode *list, int data);
NodeDataType selectElem(DoubLinkNode *list, NodeDataType elem);
DoubLinkNode *amendElem(DoubLinkNode *list, int pos, int newElem);
#endif