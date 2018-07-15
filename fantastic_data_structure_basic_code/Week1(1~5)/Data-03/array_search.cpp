//#define MY_SOL
#define REF_SOL

#ifdef MY_SOL

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
	int i;
	bool fFound=false;
	for(i=0; i<size; i++){
        if(ap[i]==sData){
            fFound = true;
            break;
        }
	}

    if(fFound==true){
        return i;
    }
    else
        return -1;

	return 0;
}

//---------------------------------------------------
void initArray(int *ap, unsigned int size)
{
	// TODO
	for(int i=0; i < size ; i++){
        ap[i] = rand()%20+1;
	}
}
//---------------------------------------------------
void printArray(int *ap, unsigned int cnt)
{
	// TODO
	int i;
	printf("�迭�� ���� : ");
	for (i = 0; i < cnt; i++) {
		printf("%5d", *ap++);
	}
	printf("\n");
}
#endif // MY_SOL

/////////////////////////////////////////////////////////////////////////////////////

#ifdef REF_SOL
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
	int pos = -1;
	unsigned int i;
	for(i=0; i<size ; i++){
        if(ap[i]==sData){
            pos = i;
            break;
        }
	}

	return pos;
}
//---------------------------------------------------
void initArray(int *ap, unsigned int size)
{
	// TODO
	for(int i=0; i < size ; i++){
        ap[i] = rand()%20+1;
	}
}
//---------------------------------------------------
void printArray(int *ap, unsigned int cnt)
{
	// TODO
	int i;
	printf("�迭�� ���� : ");
	for (i = 0; i < cnt; i++) {
		printf("%5d", *ap++);
	}
	printf("\n");
}
#endif // REF_SOL

