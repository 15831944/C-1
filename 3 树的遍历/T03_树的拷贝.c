#include <stdlib.h> 
#include <stdio.h>
#include <memory.h>
#include "TreeStructs.h"

BiTree copyTree(BiTree root)
{
	BiNode *newLptr = NULL;
	BiNode *newRptr = NULL;
	BiNode *newNode = NULL;
	if (!root)
		return NULL;
	if (root->lchild)
		newLptr = copyTree(root->lchild);
	else
		newLptr = NULL;
	if (root->rchild)
		newRptr = copyTree(root->rchild);
	else
		newRptr = NULL;
	newNode = (BiNode *)malloc(sizeof(BiNode));
	if (newNode == NULL)
		return NULL;
	newNode->lchild = newLptr;
	newNode->rchild = newRptr;
	newNode->data = root->data;
	return newNode;
}

// ʹ�ú�������ͷŴ�����������ڴ�
void freeTree(BiTree root)
{
	if (!root)
		return;
	freeTree(root->lchild);
	freeTree(root->rchild);
	free(root);
}

void preOrder31(BiTree root)
{
	if (!root)
		return;
	printf("%d ", root->data);
	preOrder31(root->lchild);
	preOrder31(root->rchild);
}

int main(void)
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

	// ������
	BiTree newTree = copyTree(&t1);

	// ͨ�������������Ƿ񿽱��ɹ�
	preOrder31(&t1);
	printf("\n");
	preOrder31(newTree);
	printf("\n");

	// �ͷ������ڴ�
	freeTree(newTree);

	return 0;
}