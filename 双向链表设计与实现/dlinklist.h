#ifndef _DATA_STRUCTURE_DOUBLELINKLIST_H
#define _DATA_STRUCTURE_DOUBLELINKLIST_H

/*
	�ŵ㣺
		1. ˫�������ڵ�����Ļ�����������ָ��ǰ����ָ��
		2. ������˫�����������ȫȡ���������ʹ��
		3. ˫�������Next��Pre��Current�������Ը�Ч�ı��������е�����Ԫ��
	ȱ�㣺
		1. ���븴��

*/

typedef void DLinkList;
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

DLinkList *DLinkList_Create();
void DLinkList_Destroy(DLinkList *list);
void DLinkList_Clear(DLinkList *list);
int DLinkList_Length(DLinkList *list);
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);
DLinkListNode* DLinkList_Get(DLinkList *list, int pos);
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node);

// ���α�����ָ������ĵ�һ������Ԫ��
DLinkListNode* DLinkList_Reset(DLinkList *list);

// ��ȡ��ǰ�α�ָ�������Ԫ��
DLinkListNode* DLinkList_Current(DLinkList *list);
// ���α��ƶ�ָ�������е���һ������Ԫ��
DLinkListNode* DLinkList_Next(DLinkList* list);

// ���α��ƶ�ָ���������һ������Ԫ��
DLinkListNode* DLinkList_Pre(DLinkList* list);

#endif // !_DATA_STRUCTURE_DOUBLELINKLIST_H
