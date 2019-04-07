#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SEQSTACK_SIZE 1024
typedef struct seqstack
{
	void *array[SEQSTACK_SIZE];
	int size;

}SEQSTACK;

typedef void * SeqStack;

// ��ʼ��ջ
SeqStack Init_seqstack();
//��ջ
int  Push_SeqStack(SeqStack stack,void*data);
//��ջ 
int  Pop_SeqStack(SeqStack stack);
//��ȡջ��
void * GetTop_SeqStack(SeqStack stack);
//ջ�Ƿ�Ϊ��
int  IsEmpty_SeqStack(SeqStack stack);
//ջ��Ԫ�صĸ���
int GetSize_SeqStack(SeqStack stack);
//����ջ
void Destroy_SeqStack(SeqStack stack);