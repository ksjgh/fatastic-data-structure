#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singlyLinkedlist.h"

BOOL dataFileLoad(List *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ����
/*----------------------------------------------------------------------------------
  �Լ��� : main()
----------------------------------------------------------------------------------*/
// int main()
// {
// 	// TODO

// 	getchar();
// 	return 0;
// }

// my solution
int main()
{
	// TODO
	List* lp;
	lp = (List*)malloc(sizeof(List));
	if(createList(lp))
	{
		dataFileLoad(lp);
		//displayList(lp);
	}

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

	// fp=fopen("..\\..\\Data_file\\flower.txt", "rt");
	fp=fopen("flower.txt", "rt");
	if(fp==NULL)
	{
	    printf("File load error!");
	    return FALSE;
	}

	while(fscanf(fp, "%s", word)!=EOF)
	{
		resp=searchNode(lp, word);  // ��ũ�帮��Ʈ ���� �ش� �ܾ �ִ� �� �˻�
		if(resp == NULL)     // �˻��� �ܾ ��ũ�帮��Ʈ ���� ������ �ܾ� ���� ���
			addLast(lp, word);
	}
	fclose(fp);
	printf("File sucessfuly loaded\n");
	return TRUE;
}
