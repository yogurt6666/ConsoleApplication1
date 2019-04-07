#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ڵ������
typedef struct node
{
	struct node *next;

}NODE;
//ά������Ľṹ��
typedef struct linklist
{
	NODE head;
	int size;

}LINKLIST;

typedef void * LinkList;

//����ĳ�ʼ��
LinkList Init_LinkList();
//����posλ�ò���ڵ�
int InsertByPos_LinkList(LinkList list, int pos, void *data);
//����posλ��ɾ���ڵ�
int DelByPos_LinkList(LinkList list, int pos);
int DelByData_LinkList(LinkList list, void *data, int(*COMPARE)(void*d1, void *d2));
//����
void Print_LinkList(LinkList list,void (*PRINT)(void*arg));
//����
void Destroy_LinkList(LinkList list);