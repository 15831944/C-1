#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

// ˫������
#define MAX_TREE_SIZE 100
typedef struct _tag_BPTNode
{
	int data;
	//int *parent; // ָ��˫�׵�ָ��
	int prarentPos; // ָ��˫�׵��±�
	char LRTag; // ���Һ��ӱ�־��0��ʾ�����Һ��ӣ�1��ʾΪ���ӣ�2��ʾΪ�Һ���
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[MAX_TREE_SIZE]; // ��Ϊ�ڵ�֮���Ƿ�ɢ�ģ���Ҫ�ѽڵ�洢��������
	int num_node; // �ڵ���Ŀ
	int root; // ���ڵ�λ�� // ע�����洢���Ǹ��ڵ���������±�
}BPTree;

int main(void)
{
	// ����������ʼ���ڴ�
	BPTree tree;
	memset(&tree, 0, sizeof(BPTree));

	BPTNode t1, t2, t3, t4, t5;
	// ��ʼ���ڴ�
	memset(&t1, 0, sizeof(BPTNode));
	memset(&t2, 0, sizeof(BPTNode));
	memset(&t3, 0, sizeof(BPTNode));
	memset(&t4, 0, sizeof(BPTNode));
	memset(&t5, 0, sizeof(BPTNode));

	// ��ʼ��data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	tree.nodes[0] = t1;
	tree.nodes[1] = t2;
	tree.nodes[2] = t3;
	tree.nodes[3] = t4;
	tree.nodes[4] = t5;
	tree.num_node = 5;
	tree.root = 0; // t1Ϊ���ĸ�

	// �������Ĺ�ϵ
	// t1������Ϊt2
	tree.nodes[1].prarentPos = 0;
	tree.nodes[1].LRTag = 1;
	// t1���Һ���Ϊt3
	tree.nodes[2].prarentPos = 0;
	tree.nodes[2].LRTag = 2;
	// t2������Ϊt4
	tree.nodes[3].prarentPos = 1;
	tree.nodes[3].LRTag = 1;
	// t3������Ϊt5
	tree.nodes[4].prarentPos = 2;
	tree.nodes[4].LRTag = 1;

	return 0;
}