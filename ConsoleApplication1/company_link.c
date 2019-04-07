#include "company_link.h"

//链表的初始化
LinkList Init_LinkList()
{
	LINKLIST *list = malloc(sizeof(LINKLIST));
	list->head.next = NULL;
	list->size = 0;

	return (LinkList)list;
}
//根据pos位置插入节点
int InsertByPos_LinkList(LinkList list, int pos, void *data)
{
	LINKLIST *mylist = (LINKLIST *)list;
	if (list == NULL || data == NULL)
		return -1;
	//如果插入的位置小于0 或大于size 则尾插
	if (pos<0 || pos >mylist->size)
		pos = mylist->size;
	NODE *pcur = &(mylist->head);
	//找到要插入节点的前驱节点
	for (int i = 0; i < pos; i++)
	{
		pcur = pcur->next;
	}
	NODE *pnew = (NODE*)data;
	pnew->next = pcur->next;
	pcur->next = pnew;
	//更新size
	mylist->size++;
	return 0;
}
//根据pos位置删除节点
int DelByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
		return -1;
	LINKLIST *mylist = (LINKLIST *)list;
	if (pos < 0 || pos >= mylist->size)
		return -1;
	NODE *pcur = &(mylist->head);
	for (int i = 0; i < pos; i++)
	{
		pcur = pcur->next;
	}
	pcur->next =  pcur->next->next;
	mylist->size--;
	return 0;
}
//根据数据删除节点
int DelByData_LinkList(LinkList list, void *data,int (*COMPARE)(void*d1,void *d2))
{
	LINKLIST *mylist = (LINKLIST *)list;
	NODE *pcur = mylist->head.next;
	for (int i = 0; i < mylist->size; i++)
	{
		//比较数据是否相同,相同删除
		if (COMPARE(pcur, data))
		{
			DelByPos_LinkList(list, i);
			return 0;
		
		}
		pcur = pcur->next;
	}
	return -1;
}
//遍历
void Print_LinkList(LinkList list, void(*PRINT)(void*arg))
{
	LINKLIST *mylist = (LINKLIST *)list;
	if (list == NULL)
		return;
	NODE *pcur = mylist->head.next;
	for (int i = 0; i < mylist->size; i++)
	{
		PRINT((void *)pcur);
		pcur = pcur->next;
	}
	printf("\n");
}
int GetSize_LinkList(LinkList list)
{
	LINKLIST *mylist = (LINKLIST *)list;
	return mylist->size;

}
//销毁
void Destroy_LinkList(LinkList list)
{
	free(list);

}