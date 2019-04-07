#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqstack.h"

int IsLeft(char ch)
{
	return ch == '(';

}
int IsRight(char ch)
{
	return ch == ')';
}
void Print_error(char *str, char *ch,char *p)
{
	int n = p - str;
	printf("%s  %s\n",str,ch);
	for (int i = 0; i < n; i++)
		printf(" ");
	printf("!\n");

}
int main1()
{
	//��ʼ��ջ
	SeqStack stack = Init_seqstack();
	//5+5*(6)+9/3*1)-(1+3(
	char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = str;
	while (*p != 0)
	{
		//����������� ѹջ
		if (IsLeft(*p))
		{
			Push_SeqStack(stack,p);
		
		}
		///�����������
		if (IsRight(*p))
		{
			//�ж�ջ�Ƿ�Ϊ�� ��Ϊ�մ�����������
			if (IsEmpty_SeqStack(stack))//Ϊ��
			{
				Print_error(str,"������û��ƥ���������",p);
			
			}
			else//��Ϊ��
			{
				Pop_SeqStack(stack);
			}
			
		}


		p++;
	
	}
	//�ж�ջ�Ƿ�Ϊ��
	while (!IsEmpty_SeqStack(stack)) // ��Ϊ�� �����Ҵ�
	{
		char *ptr =(char *)GetTop_SeqStack(stack);
		Print_error(str, "������û��ƥ���������", ptr);
		Pop_SeqStack(stack);
	
	}


	system("pause");
	return 0;
}
