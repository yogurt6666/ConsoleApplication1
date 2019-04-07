#include "seqstack.h"
// 初始化栈
SeqStack Init_seqstack()
{
	SEQSTACK *stack = malloc(sizeof(SEQSTACK));
	memset(stack->array,0x00,sizeof(stack->array));
	stack->size = 0;
	return (SeqStack)stack;
}
//入栈
int  Push_SeqStack(SeqStack stack, void*data)
{
	SEQSTACK *mystack = (SEQSTACK *)stack;
	if (stack == NULL || data == NULL)
		return -1;
	if (mystack->size >= SEQSTACK_SIZE)
	{
		printf("stack full \n");
		return -1;
	
	}
	mystack->array[mystack->size] = data;
	mystack->size++;
	return 0;

}
//出栈 
int  Pop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
		return -1;
	SEQSTACK *mystack = (SEQSTACK *)stack;
	mystack->array[mystack->size - 1] = NULL;
	mystack->size--;
	return 0;
}
//获取栈顶
void * GetTop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
		return NULL;
	SEQSTACK *mystack = (SEQSTACK *)stack;
	return mystack->array[mystack->size - 1];
}
//栈是否为空
int  IsEmpty_SeqStack(SeqStack stack)
{

	SEQSTACK *mystack = (SEQSTACK *)stack;
	if (mystack->size <= 0)
		return 1;
	return  0;
}
//栈中元素的个数
int GetSize_SeqStack(SeqStack stack)
{
	SEQSTACK *mystack = (SEQSTACK *)stack;
	return mystack->size;
}
//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	free(stack);
}