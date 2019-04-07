#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//链表的节点
typedef struct node
{

	struct node*next;
}NODE;
//维护链栈的结构体
typedef struct linkstack
{
	NODE head;
	int size;

}LINKSTACK;
typedef void* LinkStack;
//初始化
LinkStack Init_LinkStack();
//入栈
int  Push_LinkStack(LinkStack stack, void *data);
//出栈
int  Push_LinkStack(LinkStack stack);
//获取栈顶
void* GetTop_LinkStack(LinkStack stack);
//获取栈中元素 的个数
int  GetSize_LinkStack(LinkStack stack);
//栈是否为空
int  IsEmpty_LinkStack(LinkStack stack);
//销毁栈
void Destroy_LinkStack(LinkStack stack);