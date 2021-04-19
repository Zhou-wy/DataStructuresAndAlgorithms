#include "Doublelinkedlist.h"

#define flag 2 //约瑟夫环中喊2的人淘汰

int main(int argc, char *argv[])
{
    /*常规测试
    DoubLinkNode *list = DoubListInit();
    printf("list init: ");
    PrintfList(list);
    InsertNode(list, 5, 2);
    printf("after insert: ");
    PrintfList(list);

    //DeleteNodeByData(list,4);
    //printf("after delete: ");
    //PrintfList(list);
    NodeDataType d = selectElem(list, 5);
    printf("the result is %d\n", d);
    list = amendElem(list, 4, 2);
    printf("after amend: ");
    PrintfList(list);
    */

   /*约瑟夫环求解*/
    DoubLinkNode *list = DoubListInit();
    printf("The numbers of these five people are : ");
    PrintfList(list);  
    while(list->next==NULL)
    {
        NodeDataType t = selectElem(list, flag);
        list = DeleteNodeByData(list,t);
    }

    return 0;
}
