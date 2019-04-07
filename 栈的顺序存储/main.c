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
	USER_DATA p1 = { "Ð¡Óã",20 };
	USER_DATA p2 = {  "Áú¹ê",200 };
	USER_DATA p3 = {  "ÎäÆ÷",60 };
	USER_DATA p4 = {  "½£Ê¥",30 };
	USER_DATA p5 = {  "Ã¤É®",35 };
	//³õÊ¼»¯Õ»
	SeqStack stack = NULL;
	stack = Init_seqstack();
	//ÈëÕ»
	Push_SeqStack(stack,&p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);
	printf("size =%d\n", GetSize_SeqStack(stack));
	while ( !IsEmpty_SeqStack(stack) )//Õ»²»Îª¿Õ,»ñÈ¡Õ»¶¥,µ¯Õ»,
	{
		//»ñÈ¡Õ»¶¥
		USER_DATA *p = (USER_DATA*)GetTop_SeqStack(stack);
		printf("%s %d \n",p->name,p->age);
		Pop_SeqStack(stack);
	
	}
	printf("size =%d\n",GetSize_SeqStack(stack));
	Destroy_SeqStack(stack);

	system("pause");
	return 0;
}
