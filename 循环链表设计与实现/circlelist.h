#ifndef _DATA_STRUCTURE_CIRCLELIST_H_
#define _DATA_STRUCTURE_CIRCLELIST_H_

typedef void CircleList;
typedef struct _tag_CircleListNode {
	struct _tag_CircleListNode *next;
}CircleListNode;

CircleList *CircleList_Create();
void CircleList_Destroy(CircleList *list);
void CircleList_Clear(CircleList *list);
int CircleList_Length(CircleList *list);
int CircleList_Insert(CircleList *list, CircleListNode *node, int pos);
CircleListNode* CircleList_Get(CircleList *list, int pos);
CircleListNode* CircleList_Delete(CircleList *list, int pos);

// ���α�����ָ�������еĵ�һ������Ԫ��
CircleListNode* CircleList_Reset(CircleList *list);

// ��ȡ��ǰ�α�ָ�������Ԫ��
CircleListNode* CircleList_Current(CircleList *list);

// ���α��ƶ�ָ�������е���һ������Ԫ��
CircleListNode* CircleList_Next(CircleList* list);

// ֱ��ָ��ɾ�������е�ĳ������Ԫ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode *node);

#endif // !_DATA_STRUCTURE_CIRCLELIST_H_
