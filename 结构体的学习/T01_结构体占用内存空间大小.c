// ����struct��ʹ���������4���������������ռλ��������

typedef struct _tag_struct11
{
	int a;
	char b;
	char buf[9];
	int *c;
}TStruct11;

int main11(void)
{
	TStruct11 t1;
	int size = sizeof t1; // ��Ӧ����С��int��������
	return 0;
}