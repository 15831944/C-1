#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

// ��������ʾ��
typedef struct _tag_BiNode {
	int data;
	struct _tag_BiNode *lchild, *rchild;
}BiNode,*BiTree;

int main11(void)
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

	return 0;
}
