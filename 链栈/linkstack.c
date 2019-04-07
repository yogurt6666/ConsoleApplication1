#include "linkstack.h"
//��ʼ��
LinkStack Init_LinkStack()
{
	LINKSTACK *stack = malloc(sizeof(LINKSTACK));
	stack->head.next = NULL;
	stack->size = 0;
	return (LinkStack)stack;
}
//��ջ
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
//��ջ
int  Pop_LinkStack(LinkStack stack)
{
	
	if (stack == NULL )
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	if (mystack->head.next == NULL)//ֻ��Ҫ��һ���ڵ�
		return -1;
	mystack->head.next = mystack->head.next->next;
	mystack->size--;
	return 0;
}
//��ȡջ��
void* GetTop_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	return mystack->head.next;
}
//��ȡջ��Ԫ�� �ĸ���
int  GetSize_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	return mystack->size;
}
//ջ�Ƿ�Ϊ��
int  IsEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
		return -1;
	LINKSTACK *mystack = (LINKSTACK *)stack;
	if (mystack->size <= 0)
		return 1;
	return 0;

}
//����ջ
void Destroy_LinkStack(LinkStack stack)
{
	free(stack);

}