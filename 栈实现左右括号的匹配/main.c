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
	//³õÊ¼»¯Õ»
	SeqStack stack = Init_seqstack();
	//5+5*(6)+9/3*1)-(1+3(
	char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = str;
	while (*p != 0)
	{
		//Èç¹ûÊÇ×óÀ¨ºÅ Ñ¹Õ»
		if (IsLeft(*p))
		{
			Push_SeqStack(stack,p);
		
		}
		///Èç¹ûÊÇÓÒÀ¨ºÅ
		if (IsRight(*p))
		{
			//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ ²»Îª¿Õ´ú±íÓÐ×óÀ¨ºÅ
			if (IsEmpty_SeqStack(stack))//Îª¿Õ
			{
				Print_error(str,"ÓÒÀ¨ºÅÃ»ÓÐÆ¥ÅäµÄ×óÀ¨ºÅ",p);
			
			}
			else//²»Îª¿Õ
			{
				Pop_SeqStack(stack);
			}
			
		}


		p++;
	
	}
	//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
	while (!IsEmpty_SeqStack(stack)) // ²»Îª¿Õ ¼ÌÐøÕÒ´í
	{
		char *ptr =(char *)GetTop_SeqStack(stack);
		Print_error(str, "×óÀ¨ºÅÃ»ÓÐÆ¥ÅäµÄÓÒÀ¨ºÅ", ptr);
		Pop_SeqStack(stack);
	
	}


	system("pause");
	return 0;
}
