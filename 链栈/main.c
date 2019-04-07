#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkstack.h"
typedef struct user_data
{
	void *ptr;
	char name[128];
	int age;

}USER_DATA;
int main()
{
	USER_DATA p1 = { NULL,"С��",20 };
	USER_DATA p2 = { NULL, "����",200 };
	USER_DATA p3 = { NULL, "����",60 };
	USER_DATA p4 = { NULL,"��ʥ",30 };
	USER_DATA p5 = { NULL, "äɮ",35 };
	//��ʼ��ջ
	LinkStack stack = NULL;
	stack = Init_LinkStack();
	//��ջ
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);
	Push_LinkStack(stack, &p4);
	Push_LinkStack(stack, &p5);
	printf("size =%d\n", GetSize_LinkStack(stack));
	while (!IsEmpty_LinkStack(stack))//ջ��Ϊ��,��ȡջ��,��ջ,
	{
		//��ȡջ��
		USER_DATA *p = (USER_DATA*)GetTop_LinkStack(stack);
		printf("%s %d \n", p->name, p->age);
		Pop_LinkStack(stack);

	}
	printf("size =%d\n", GetSize_LinkStack(stack));
	Destroy_LinkStack(stack);

	system("pause");
	return 0;
}
