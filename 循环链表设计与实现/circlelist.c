#include "circlelist.h"
#include <stdlib.h>
#include <memory.h>

typedef struct _tag_CircleList
{
	CircleListNode header; // ͷ�ڵ�
	CircleListNode *slider; // �α�
	int length;
}TCircleList;

CircleList *CircleList_Create()
{
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL)
		return ret;
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}
void CircleList_Destroy(CircleList *list)
{
	if (list == NULL)
		return;
	free(list);
	return;
}
void CircleList_Clear(CircleList *list)
{
	if (list == NULL)
		return;
	TCircleList *tlist = (TCircleList *)list;
	tlist->header.next = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
	return;
}
int CircleList_Length(CircleList *list)
{
	if (list == NULL)
		return -1;
	TCircleList *tlist = (TCircleList *)list;
	return tlist->length;
}
int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
		return -1;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &tlist->header;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	node->next = current->next;
	current->next = node;

	// ���ǵ�һ�β���
	if (tlist->length == 0)
		tlist->slider = node;
	tlist->length++;

	// ��ͷ�巨 current��Ȼָ��ͷ��(ԭ����0����û������)
	if (current == (CircleListNode *)tlist)
	{
		// ��ȡ���һ��Ԫ��
		CircleListNode *last = CircleList_Get(tlist, tlist->length - 1);
		last->next = current->next;
	}

	return 0;
}
CircleListNode* CircleList_Get(CircleList *list, int pos)
{
	CircleListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode* current = &tlist->header;
	for (int i = 0; i < pos; i++)
		current = current->next;
	ret = current->next;
	return ret;
}
CircleListNode* CircleList_Delete(CircleList *list, int pos)
{
	CircleListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &tlist->header;
	CircleListNode *last = NULL;
	for (int i = 0; i < pos; i++)
		current = current->next;
	// ��ɾ����һ��Ԫ��(ͷ�ڵ�)
	if (current = &tlist->header)
		last = (CircleListNode *)CircleList_Get(tlist, tlist->length - 1);
	ret = current->next;
	current->next = ret->next;
	
	tlist->length--;
	// �ж������Ƿ�Ϊ��
	if (last != NULL)
	{
		tlist->header.next = ret->next;
		last->next = ret->next;
	}

	// ��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
	if (tlist->slider == ret)
	{
		tlist->slider = ret->next;
	}

	// ��ɾ��Ԫ�غ�������Ϊ0
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return ret;
}

// ֱ��ָ��ɾ�������е�ĳ������Ԫ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode *node)
{
	CircleListNode *ret = NULL;
	if (list == NULL || node == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode* current = &tlist->header;
	for (int i = 0; i < tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			// ���ret�ҵ�������iȥɾ��
			CircleList_Delete(tlist, i);
			break;
		}
		current = current->next;
	}
	return ret;
}

// ���α�����ָ�������еĵ�һ������Ԫ��
CircleListNode* CircleList_Reset(CircleList *list)
{
	CircleListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	tlist->slider = tlist->header.next;
	ret = tlist->slider;
	return ret;
}

// ��ȡ��ǰ�α�ָ�������Ԫ��
CircleListNode* CircleList_Current(CircleList *list)
{
	if (list == NULL)
		return NULL;
	TCircleList *tlist = (TCircleList *)list;
	return tlist->slider;
}

// ���α��ƶ�ָ�������е���һ������Ԫ��
CircleListNode* CircleList_Next(CircleList* list)
{
	CircleListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}

