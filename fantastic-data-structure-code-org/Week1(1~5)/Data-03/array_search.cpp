
#include <stdio.h>
#include <stdlib.h>
void printArray(int *ap, unsigned int cnt); // �迭���� ��� �Լ�
void initArray(int *ap, unsigned int size); // 1~20������ ������ �迭�ʱ�ȭ�ϴ� �Լ�
int searchArray(int *ap, unsigned int size, int sData); // �˻��Լ�

int main()
{
	int num[10];		// ������ ���� �迭
	unsigned int size;  // �迭�� ũ��(���� ����) ����
	int sData;			// �˻��� ������ ����
	int res=0;			// �˻� ��� ����
	int i;
	size = sizeof(num)/sizeof(num[0]);	// �迭 ũ�� ���

	initArray(num, size);
	printArray(num, size);

	for(i=0; i<5; i++){
		printf("# �˻��� ������ �Է��Ͻÿ� : ");
		scanf("%d", &sData);
		res = searchArray(num, size, sData);
		if(res!=-1)
			printf("%d�� %d�� �濡 �ֽ��ϴ�.\n", sData, res);
		else
			printf("%d�� �������� �ʽ��ϴ�.\n", sData);
	}
	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
int searchArray(int *ap, unsigned int size, int sData)
{
	// TODO

	return 0;
}
//---------------------------------------------------
void initArray(int *ap, unsigned int size)
{
	// TODO
}
//---------------------------------------------------
void printArray(int *ap, unsigned int cnt)
{
	// TODO
}

