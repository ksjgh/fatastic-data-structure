
#include <stdio.h>
#include <string.h>

void inputString(char *cp);
int checkPalindrome(char *cp);

int main()
{
	char str[80];		// ���ڿ� ���� �迭
	int res;			// ȸ�� �˻� ��� ����

	inputString(str);
	while(strcmp(str,"end")!=0){
		res = checkPalindrome(str);
		if(res==1)
			printf("\"%s\" : ȸ���Դϴ�.\n", str);
		else
			printf("\"%s\" : ȸ���� �ƴմϴ�.\n", str);
		inputString(str);
	}

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void inputString(char *cp)
{
	printf("# ȸ�� �˻��� ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", cp);
	return;
}
//---------------------------------------------------
int checkPalindrome(char *cp)
{
	// TODO
	return 0;
}