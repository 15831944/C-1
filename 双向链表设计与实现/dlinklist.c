#include "dlinklist.h"
#include <stdlib.h>
#include <memory.h>

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DLinkList *DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (ret == NULL)
		return ret;
	memset(ret, 0, sizeof(TDLinkList));
	ret->header.next = NULL;
	ret->header.pre = NULL;
	ret->length = 0;
	ret->slider = NULL;
	return ret;
}
void DLinkList_Destroy(DLinkList *list)
{
	if (list == NULL)
		return;
	free(list);
	return;
}
void DLinkList_Clear(DLinkList *list)
{
	if (list == NULL)
		return;
	TDLinkList *tlist = (TDLinkList *)list;
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
	return;
}
int DLinkList_Length(DLinkList *list)
{
	if (list == NULL)
		return 0;
	TDLinkList *tlist = (TDLinkList *)list;
	return tlist->length;
}
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode* current = &tlist->header;
	DLinkListNode* next = NULL; // ��Ҫ����next����ָ�����
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	next = current->next;

	// ����1
	current->next = node;
	node->next = next;
	if (next != NULL)
	{
		next->pre = node;
	}
	if (tlist->length == 0)
		tlist->slider = node;  // ����������һ��Ԫ�ش����α�
	
	// ����0λ�ò��룬��Ҫ���⴦�� �����ڵ�nextǰpreָ��null
	if (current == &tlist->header)
		node->pre = NULL;
	tlist->length++;
	return 0;
}
DLinkListNode* DLinkList_Get(DLinkList *list, int pos)
{
	DLinkListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode* current = &tlist->header;
	// �˴������Ż���ʹ��pre���ж�pos��length�Ĺ�ϵ
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	ret = current->next;
	return ret;
}
// ɾ���������һ���ڵ㣬����δ���
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos)
{
	DLinkListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode* current = &tlist->header;
	DLinkListNode* next = NULL;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	ret = current->next;
	if(ret != NULL)
		next = ret->next;

	// ����1
	current->next = next;
	if (next != NULL) // ��Ҫ���⴦��
	{
		next->pre = current;
		if (current == &tlist->header) // ����0��λ�ã���Ҫ���⴦��
			next->pre = NULL;
	}
	if (tlist->slider == ret)
		tlist->slider = next;
	tlist->length--;
	return ret;
}
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node)
{
	DLinkListNode* ret = NULL;
	if (list == NULL != node == NULL)
		return ret;
	TDLinkList* tlist = (TDLinkList *)list;
	DLinkListNode* current = &tlist->header;
	for (int i = 0; i < tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			DLinkList_Delete(tlist, i);
			break;
		}
		current = current->next;
	}
	return ret;
}
DLinkListNode* DLinkList_Reset(DLinkList *list)
{
	DLinkListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TDLinkList* tlist = (TDLinkList *)list;
	tlist->slider = tlist->header.next;
	ret = tlist->slider;
	return ret;
}
DLinkListNode* DLinkList_Current(DLinkList *list)
{
	DLinkListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TDLinkList* tlist = (TDLinkList *)list;
	ret = tlist->slider;
	return ret;
}
DLinkListNode* DLinkList_Next(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TDLinkList* tlist = (TDLinkList *)list;
	ret = tlist->slider;
	if (tlist->slider != NULL)
		tlist->slider = ret->next;
	return ret;
}
DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TDLinkList* tlist = (TDLinkList *)list;
	ret = tlist->slider;
	if (tlist->slider != NULL)
		tlist->slider = ret->pre;
	return ret;
}