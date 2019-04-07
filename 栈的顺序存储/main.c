#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqstack.h"
typedef struct user_data
{
	char name[128];
	int age;

}USER_DATA;
int main()
{
	USER_DATA p1 = { "С��",20 };
	USER_DATA p2 = {  "����",200 };
	USER_DATA p3 = {  "����",60 };
	USER_DATA p4 = {  "��ʥ",30 };
	USER_DATA p5 = {  "äɮ",35 };
	//��ʼ��ջ
	SeqStack stack = NULL;
	stack = Init_seqstack();
	//��ջ
	Push_SeqStack(stack,&p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);
	printf("size =%d\n", GetSize_SeqStack(stack));
	while ( !IsEmpty_SeqStack(stack) )//ջ��Ϊ��,��ȡջ��,��ջ,
	{
		//��ȡջ��
		USER_DATA *p = (USER_DATA*)GetTop_SeqStack(stack);
		printf("%s %d \n",p->name,p->age);
		Pop_SeqStack(stack);
	
	}
	printf("size =%d\n",GetSize_SeqStack(stack));
	Destroy_SeqStack(stack);

	system("pause");
	return 0;
}
