#include <stdio.h>
void inputArray(int (*p)[4], int row);
void outputArray(int (*p)[4], int row);

int main()
{
	int  num[3][4];
	int row;
	row = sizeof(num)/sizeof(num[0]); // ���� ���� ���ϱ�
	inputArray(num, row);
	outputArray(num, row);

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void inputArray(int (*p)[4], int row)
{
	int i, j;
	for( i = 0 ; i < row ; i++ ){
		for( j = 0 ; j < 4 ; j ++ ){
			printf("%d�� %d�� ���� �� �Է� : " , i, j);
			scanf("%d", &p[i][j] ) ;
		}
	}
	return;
}
//---------------------------------------------------
void outputArray(int (*p)[4], int row)
{
	// TODO
}
