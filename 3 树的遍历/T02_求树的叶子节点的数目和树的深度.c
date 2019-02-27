#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "TreeStructs.h"

void CountLeafNum(BiTree root,int *count)
{
	if (!root || !count)
		return;
	if (!root->lchild && !root->rchild)
	{
		(*count)++;
		printf("%d ", root->data);
	}
	CountLeafNum(root->lchild, count);
	CountLeafNum(root->rchild, count);
}

int TreeDepth(BiTree root)
{
	int depth = 0;
	if (!root)
		return depth;
	int depthleft = TreeDepth(root->lchild);
	int depthright = TreeDepth(root->rchild);
	depth = (depthleft > depthright) ? depthleft : depthright + 1;
	return depth;
}

int main21(void)
{
	BiNode t1, t2, t3, t4, t5;
	// ��ʼ���ڴ�
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	// ��ʼ��data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	// �������Ĺ�ϵ
	// t1������Ϊt2
	t1.lchild = &t2;
	// t1���Һ���Ϊt3
	t1.rchild = &t3;
	// t2������Ϊt4
	t2.lchild = &t4;
	// t3������Ϊt5
	t3.lchild = &t5;

	int count = 0;
	int depth = 0;
	CountLeafNum(&t1, &count);
	printf("\n������Ҷ�ӽڵ�ĸ���Ϊ��%d\n", count);
	depth = TreeDepth(&t1);
	printf("���ĸ߶�Ϊ��%d\n", depth);
	return 0;
}