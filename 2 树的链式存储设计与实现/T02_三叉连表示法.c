#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

// ��������ʾ��
typedef struct _tag_TriTNode
{
	int data;
	// ���Һ���ָ��
	struct _tag_TriTNode *lchild, *rchild;
	// ָ��˫�׵�ָ��
	struct _tag_TriTNode *parent;
}TriTNode,*TriTree;

int main21(void)
{
	TriTNode t1, t2, t3, t4, t5;
	// ��ʼ���ڴ�
	memset(&t1, 0, sizeof(TriTNode));
	memset(&t2, 0, sizeof(TriTNode));
	memset(&t3, 0, sizeof(TriTNode));
	memset(&t4, 0, sizeof(TriTNode));
	memset(&t5, 0, sizeof(TriTNode));

	// ��ʼ��data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	// �������Ĺ�ϵ
	// t1������Ϊt2
	t1.lchild = &t2;
	t2.parent = &t1;
	// t1���Һ���Ϊt3
	t1.rchild = &t3;
	t3.parent = &t1;
	// t2������Ϊt4
	t2.lchild = &t4;
	t4.parent = &t2;
	// t3������Ϊt5
	t3.lchild = &t5;
	t5.parent = &t3;

	return 0;
	return 0;
}