#include "listQueue.h"
#include <stdio.h>
//--------------------------------------------------------------------------------
//   main()
//--------------------------------------------------------------------------------
int main()
{
	Queue que; /* ť����*/
	int N, M;   /* N : �ο���, M : ���� �� */
	int i;
	int getData;   /* deueue�� ������ ���� ���� */

	createQueue(&que); /* ť ���� �� �ʱ�ȭ*/

	printf("N(�ο���)�� M(���ݼ�)�� �Է��Ͻÿ� (M<=N) : ");
	scanf("%d %d", &N, &M);

	// TODO

	destroyQueue(&que);
	getchar(); getchar();
	return 0;
}

