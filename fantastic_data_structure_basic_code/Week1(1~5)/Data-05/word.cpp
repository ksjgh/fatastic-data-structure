#include <stdio.h>
#include <string.h>
void inputString(char (*p)[80], int row);
void outputString(char (*p)[80], int row);
int main()
{
	char word[5][80];
	int row;
	row = sizeof(word)/sizeof(word[0]); // ���� ���� ���ϱ�
	inputString(word, row);
	outputString(word, row);

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void inputString(char (*p)[80], int row)
{
	// TODO
	return;
}
//---------------------------------------------------
void outputString(char (*p)[80], int row)
{
	// TODO
	return;
}

