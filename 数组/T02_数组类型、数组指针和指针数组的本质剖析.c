#include <stdio.h>

// ����һ���������ͣ� int[5]
typedef int ArrayType21[5];

// ����һ������ָ�����ͣ�������һ���������͵�ָ�룩
typedef int(*ArrayPointType21)[5];

// ����һ��ָ���������ͣ�ָ�����������Ϊint[5]��������洢������Ϊ��int *
typedef int *PointArrayType21[5];

int main21(void)
{
	ArrayType21 arr;
	ArrayPointType21 arrp;
	PointArrayType21 parr;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

	// �������ͺ�����ָ�����͵Ĺ�ϵ
	arrp = &arr;
	for (int i = 0; i < len; i++)
		printf("%d  ", (*arrp)[i]);
	printf("\n");

	// ָ���������ͺ��������͵Ĺ�ϵ
	for (int i = 0; i < len; i++)
		parr[i] = &arr[i];
	for (int i = 0; i < len; i++)
		printf("%d  ", *parr[i]);
	printf("\n");
	return 0;
}

