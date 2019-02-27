#include "seqlist.h"
#include <stdlib.h>

typedef struct _Teacher {
	int age;
	char name[64];
}Teacher;

int main(void)
{
	int ret = 0;
	SeqList *list = NULL;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err: ret = %d\n", ret);
		return ret;
	}
	// ����ͷ�巨����Ԫ��
	ret = SeqList_Insert(list, (SeqListNode *)&t1, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t3, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t4, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t5, 0);

	// ��ӡ�洢��Ϣ
	printf("length: %d\n", SeqList_Length(list));
	printf("capacity: %d\n", SeqList_Capacity(list));

	// ����
	for (int i = 0; i < SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			printf("func SeqList_Get() err: ret = %d\n", ret);
			// �����ڴ�й©����
			SeqList_Destroy(list);
			return ret;
		}
		printf("tmp->age: %d\n", tmp->age);
	}
	// ɾ�������еĽڵ�
	while (SeqList_Length(list) > 0)
		SeqList_Delete(list, 0);

	SeqList_Destroy(list);
	return 0;
}