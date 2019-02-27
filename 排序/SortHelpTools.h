#ifndef _ALGORITHM_SORTHELPTOOLS_H
#define _ALGORITHM_SORTHELPTOOLS_H
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include "commonTools.h"

typedef void(*sortFuncDT)(int arr[], int n);

// �������int�����飬��Χ��[l,r]
int generatorRandomIntArray(int **arr/*out*/, int n, int l, int r)
{
	assert(n > 0 && r >= l);
	int *intArr = (int *)malloc(sizeof(int) * n);
	if (NULL == intArr)
		return -1;
	// ��ʼ��������ڴ�
	memset(intArr, 0, sizeof(int) * n);
	// ʹ��ʱ�������������
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		intArr[i] = rand() % (r - l + 1) + l;
	*arr = intArr;
	return 0;
}

// ���ɽ����������������
int generatorNearlyOrderedArray(int **arr/*out*/, int n, int swaptimes)
{
	assert(n > 0 && swaptimes >= 0);
	// �����ڴ�
	int *intArr = (int *)malloc(sizeof(int)*n);
	if (NULL == intArr)
		return -1;
	// ��ʼ��������ڴ�
	memset(intArr, 0, sizeof(int)*n);

	// ʹ��ʱ����Ϊ�������
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		intArr[i] = i;
	for (int i = 0; i < swaptimes; i++)
	{
		int posX = rand() % n;
		int posY = rand() % n;
		swap(&intArr[posX], &intArr[posY]);
	}
	*arr = intArr;
	return 0;
}

// �ж��Ƿ����򣬷���0���������-1��������
int isSorted(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return -1;
	return 0;
}

// �������ʱ��
void Sort(const char *sortName, sortFuncDT sortFunc, int arr[], int n)
{
	assert(sortName != NULL && sortFunc != NULL && arr != NULL && n > 0);
	clock_t startTime, endTime;
	startTime = clock();
	sortFunc(arr, n);
	endTime = clock();
	if (isSorted(arr, n) == 0)
		printf("%s: sort success... times: %lf s\n", sortName, (double)(endTime - startTime) / CLOCKS_PER_SEC);
	else
		printf("%s: sort failed!!!\n");
}

#endif // !_ALGORITHM_SORTHELPTOOLS_H
