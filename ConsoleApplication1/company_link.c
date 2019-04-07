#include "company_link.h"

//����ĳ�ʼ��
LinkList Init_LinkList()
{
	LINKLIST *list = malloc(sizeof(LINKLIST));
	list->head.next = NULL;
	list->size = 0;

	return (LinkList)list;
}
//����posλ�ò���ڵ�
int InsertByPos_LinkList(LinkList list, int pos, void *data)
{
	LINKLIST *mylist = (LINKLIST *)list;
	if (list == NULL || data == NULL)
		return -1;
	//��������λ��С��0 �����size ��β��
	if (pos<0 || pos >mylist->size)
		pos = mylist->size;
	NODE *pcur = &(mylist->head);
	//�ҵ�Ҫ����ڵ��ǰ���ڵ�
	for (int i = 0; i < pos; i++)
	{
		pcur = pcur->next;
	}
	NODE *pnew = (NODE*)data;
	pnew->next = pcur->next;
	pcur->next = pnew;
	//����size
	mylist->size++;
	return 0;
}
//����posλ��ɾ���ڵ�
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
//��������ɾ���ڵ�
int DelByData_LinkList(LinkList list, void *data,int (*COMPARE)(void*d1,void *d2))
{
	LINKLIST *mylist = (LINKLIST *)list;
	NODE *pcur = mylist->head.next;
	for (int i = 0; i < mylist->size; i++)
	{
		//�Ƚ������Ƿ���ͬ,��ͬɾ��
		if (COMPARE(pcur, data))
		{
			DelByPos_LinkList(list, i);
			return 0;
		
		}
		pcur = pcur->next;
	}
	return -1;
}
//����
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
//����
void Destroy_LinkList(LinkList list)
{
	free(list);

}