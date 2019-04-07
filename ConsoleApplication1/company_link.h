#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//链表节点的类型
typedef struct node
{
	struct node *next;

}NODE;
//维护链表的结构体
typedef struct linklist
{
	NODE head;
	int size;

}LINKLIST;

typedef void * LinkList;

//链表的初始化
LinkList Init_LinkList();
//根据pos位置插入节点
int InsertByPos_LinkList(LinkList list, int pos, void *data);
//根据pos位置删除节点
int DelByPos_LinkList(LinkList list, int pos);
int DelByData_LinkList(LinkList list, void *data, int(*COMPARE)(void*d1, void *d2));
//遍历
void Print_LinkList(LinkList list,void (*PRINT)(void*arg));
//销毁
void Destroy_LinkList(LinkList list);