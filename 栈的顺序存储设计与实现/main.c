#include <stdlib.h>
#include <stdio.h>
#include "seqstack.h"

int main(void)
{
	PSeqStack stack = SeqStack_Create(10);
	int arr[50];
	if (stack == NULL)
		return -1;

	// ѹջ
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i + 1;
		SeqStack_Push(stack, &arr[i]);
	}
	
	// ��ӡջ�ĳ�����Ϣ
	printf("stack length: %d\n", SeqStack_Size(stack));
	printf("stack capacity: %d\n", SeqStack_Capacity(stack));
	printf("stack top item: %d\n", *((int *)SeqStack_Top(stack)));

	// ��ջ
	printf("pop stack item: ");
	while (SeqStack_Size(stack) > 0)
	{
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("%d  ", tmp);
	}
	printf("\n");
	SeqStack_Destroy(stack);
	return 0;
}