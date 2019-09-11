#include <stdio.h>
#include <string.h>
#include "singlyLinkedlist.h"
BOOL dataFileLoad(List *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ����
/*----------------------------------------------------------------------------------
  �Լ��� : main()
----------------------------------------------------------------------------------*/
int main()
{
	// TODO

	getchar();
	return 0;
}

/*----------------------------------------------------------------------------------
  �Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
BOOL dataFileLoad(List *lp) // ������ ���ϳ��� �����͸� ����Ʈ�� ����
{
	FILE *fp;
	char word[80];
	Node *resp;

	fp=fopen("d:\\data\\flower.txt", "rt");
	if(fp==NULL)
		return FALSE;

	while(fscanf(fp, "%s", word)!=EOF)
	{
		resp=searchNode(lp, word);  // ��ũ�帮��Ʈ ���� �ش� �ܾ �ִ� �� �˻�
		if(resp == NULL)     // �˻��� �ܾ ��ũ�帮��Ʈ ���� ������ �ܾ� ���� ���
			addLast(lp, word);
	}
	fclose(fp);
	return TRUE;
}
