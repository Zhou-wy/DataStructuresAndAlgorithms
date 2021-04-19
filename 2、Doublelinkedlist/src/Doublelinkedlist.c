#include "Doublelinkedlist.h"

DoubLinkNode *DoubListInit()
{
    DoubLinkNode *head = (DoubLinkNode *)malloc(sizeof(DoubLinkNode));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    DoubLinkNode *list = head;
    for (int i = 2; i <= 5; i++)
    {
        //创建新的节点并初始化
        DoubLinkNode *body = (DoubLinkNode *)malloc(sizeof(DoubLinkNode));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;
        //新节点与链表最后一个节点建立关系
        list->next = body;
        body->prior = list;
        //list永远指向链表中最后一个节点
        list = list->next;
    }
    return head;
}
void PrintfList(DoubLinkNode *list)
{
    if (list == NULL)
        return;
    DoubLinkNode *temp = list;
    while (temp)
    {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL)
        {
            printf("%d\n", temp->data);
        }
        else
        {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}

DoubLinkNode *InsertNode(DoubLinkNode *list, NodeDataType data, int pos)
{
    if (list == NULL)
        return -1;
    DoubLinkNode *NewNode = (DoubLinkNode *)malloc(sizeof(DoubLinkNode));
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prior = NULL;
    //插入到链表头，要特殊考虑
    if (pos == 1)
    {
        NewNode->next = list;
        list->prior = NewNode;
        list = NewNode;
    }
    //插入链表中
    else
    {
        DoubLinkNode *pCurrent = list; //辅助指针，找到插入位置的前一个节点
        for (int i = 0; i < pos - 1; i++)
        {
            pCurrent = pCurrent->next;
        }
        if (pCurrent->next == NULL) //说明插入点是尾部
        {
            pCurrent->next = NewNode;
            NewNode->prior = pCurrent;
        }
        else //说明插入点是中间
        {
            pCurrent->next->prior = NewNode;
            NewNode->next = pCurrent->next;
            pCurrent->next = NewNode;
            NewNode->prior = pCurrent;
        }
    }
    return list;
}

DoubLinkNode *DeleteNodeByData(DoubLinkNode *list, int data)
{
    if (list == NULL)
        return -1;
    DoubLinkNode *pCurrent = list;
    while (pCurrent)
    {
        if (pCurrent->data == data)
        {

            pCurrent->next->prior = pCurrent->prior;
            //pCurrent->prior->next = pCurrent->next;
            free(pCurrent);
            return list;
        }
        pCurrent = pCurrent->next;
    }
    printf("tThis list doesn't have this element\n");
    return list;
}

NodeDataType selectElem(DoubLinkNode *list, NodeDataType elem)
{
    //新建一个指针t，初始化为头指针 head
    DoubLinkNode *t = list;
    int i = 1;
    while (t)
    {
        if (t->data == elem)
        {
            return i;
        }
        i++;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}
//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
DoubLinkNode *amendElem(DoubLinkNode *list, int pos, int newElem)
{
    DoubLinkNode *temp = list;
    //遍历到被删除结点
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->data = newElem;
    return list;
}
