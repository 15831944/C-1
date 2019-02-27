#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _tag_Teacher {
	LinkListNode node;
	int age;
	char name[64];
}Teacher;
int main(void)
{
	int ret = 0;
	LinkList *list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;
	
	// ��������
	list = LinkList_Create();
	if (list == NULL)
		return -1;

	// ������㷨�;����ҵ��ڵ�ķ���
	ret = LinkList_Insert(list, (LinkListNode*)(&t1), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t2), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t3), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t4), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t5), 0);

	// ��ȡ����ĳ�����Ϣ
	printf("list length: %d\n", LinkList_Length(list));

	// ����
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		printf("tmp->age: %d\n", tmp->age);
	}

	// ɾ��Ԫ��
	while (LinkList_Length(list) != 0)
	{
		LinkList_Delete(list, 0);
	}
	LinkList_Destroy(list);
	return ret;
}