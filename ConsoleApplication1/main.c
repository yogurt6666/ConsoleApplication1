#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "company_link.h"
typedef struct user_data
{
	void *ptr;
	char name[128];
	int age;

}USER_DATA;
void  MyPrint(void *data)
{
	USER_DATA *p = (USER_DATA *)data;
	printf("%s %d \n",p->name,p->age);




}
int Compare(void *d1, void *d2)
{
	USER_DATA *p1 = (USER_DATA*)d1;
	USER_DATA *p2 = (USER_DATA*)d2;
	return (strcmp(p1->name, p2->name) == 0) && (p1->age == p2->age);
}
int main()
{
	USER_DATA p1 = {NULL,"С��",20};
	USER_DATA p2 = { NULL, "����",200 };
	USER_DATA p3 = { NULL, "����",60 };
	USER_DATA p4 = { NULL, "��ʥ",30 };
	USER_DATA p5 = { NULL, "äɮ",35 };
	LinkList list=NULL;
	//��ʼ������
	list = Init_LinkList();
	//����
	InsertByPos_LinkList(list,0,&p1);
	InsertByPos_LinkList(list, 0, &p2);
	InsertByPos_LinkList(list, 0, &p3);
	InsertByPos_LinkList(list, 1, &p4);
	InsertByPos_LinkList(list, 3, &p5);
	//���� ��ʥ ���� äɮ С��
	//����
	Print_LinkList(list, MyPrint);
	//DelByPos_LinkList(list,1 );
	DelByData_LinkList(list,&p4, Compare);
	Print_LinkList(list, MyPrint);
	//����
	Destroy_LinkList(list);



	system("pause");
	return 0;
}

