#include "linkstack.h"
//初始化
LinkStack Init_LinkStack()
{
	LINKSTACK *stack = malloc(sizeof(LINKSTACK));
	stack->head.next = NULL;
	stack->size = 0;
	return (LinkStack)stack;
}
//入栈
int  Push_LinkStack(LinkStack stack, void *data)
{
	if (stack == NULL || data == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	NODE *pnew = (NODE*)data;
	pnew->next = mystack->head.next;
	mystack->head.next = pnew;
	mystack->size++;
	return 0;
}
//出栈
int  Pop_LinkStack(LinkStack stack)
{
	
	if (stack == NULL )
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	if (mystack->head.next == NULL)//只是要有一个节点
		return -1;
	mystack->head.next = mystack->head.next->next;
	mystack->size--;
	return 0;
}
//获取栈顶
void* GetTop_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	return mystack->head.next;
}
//获取栈中元素 的个数
int  GetSize_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	return mystack->size;
}
//栈是否为空
int  IsEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	if (mystack->size <= 0)
		return 1;
	return 0;

}
//销毁栈
void Destroy_LinkStack(LinkStack stack)
{
	free(stack);

}