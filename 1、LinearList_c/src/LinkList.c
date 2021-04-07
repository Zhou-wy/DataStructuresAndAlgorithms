#include "LinkList.h"

LinKList *Init_LinkList()
{
    LinKList *list = (LinKList *)malloc(sizeof(LinKList));
    list->size = 0;
    list->head = (LinkNode *)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
}
void Insert_LinkList(LinKList *list, int pos, void *data)
{
    if (list == NULL || data == NULL)
        return;
    if (pos < 0 || pos > list->size)
        pos = list->size;
    //创建新节点
    LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    //找节点
    LinkNode *pCurrent = list->head; //辅助指针
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //新节点入链表
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    list->size++;
}
void RemoveByBos_linkList(LinKList *list, int pos)
{
    if (list == NULL)
        return;
    if (pos < 0 || pos >= list->size)
        return;
    //查找删除的前一个节点
    LinkNode *pCurrent = list->head;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //缓存待删除的节点
    LinkNode *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    //释放删除节点的内存
    free(pDel);
    list->size--;
}
int Size_linkList(LinKList *list)
{
    return list->size;
}
void *Front_LinkList(LinKList *list)
{
    return list->head->next->data;
}
void FreeSpace_LinkList(LinKList *list)
{
    if (list == NULL)
        return;
    LinkNode *pCurrent = list->head;
    while (pCurrent != NULL)
    {
        //缓存下一个节点
        LinkNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    list->size = 0;
    free(list);
}
int Find_LinkList(LinKList *list, void *data)
{
    if (list == NULL || data == NULL)
        return -1;
    int i;
    LinkNode *pCurrent = list->head->next;
    while (pCurrent != NULL)
    {
        if (pCurrent->data == data)
        {
            break;
        }
        i++;
        pCurrent = pCurrent->next;
    }
    return i;
}
void Printf_LinkList(LinKList *list, PRINTFLINKNODE print)
{
    if (list == NULL)
        return;
    LinkNode *pCurrent = list->head->next;
    while (pCurrent != NULL)
    {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}
