#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//����Ľڵ�
typedef struct node
{

	struct node*next;
}NODE;
//ά����ջ�Ľṹ��
typedef struct linkstack
{
	NODE head;
	int size;

}LINKSTACK;
typedef void* LinkStack;
//��ʼ��
LinkStack Init_LinkStack();
//��ջ
int  Push_LinkStack(LinkStack stack, void *data);
//��ջ
int  Push_LinkStack(LinkStack stack);
//��ȡջ��
void* GetTop_LinkStack(LinkStack stack);
//��ȡջ��Ԫ�� �ĸ���
int  GetSize_LinkStack(LinkStack stack);
//ջ�Ƿ�Ϊ��
int  IsEmpty_LinkStack(LinkStack stack);
//����ջ
void Destroy_LinkStack(LinkStack stack);