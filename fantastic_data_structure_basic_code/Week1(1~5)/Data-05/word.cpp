//////template
//#define MY_SOL
//#define REF_SOL
//
//#ifdef MY_SOL
//
//#endif // MY_SOL
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//#ifdef REF_SOL
//
//#endif // REF_SOL



#define MY_SOL
//#define REF_SOL

#ifdef MY_SOL
    #include <stdio.h>
    #include <string.h>
    void inputString(char (*p)[80], int row);
    void outputString(char (*p)[80], int row);
    int main()
    {
        char word[5][80];
        int row;
        row = sizeof(word)/sizeof(word[0]); // 행의 개수 구하기
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
        int j;
        for(j=0 ; j<row; j++){
            printf("#%d번 문자열을 입력하시오 : ",j);
            scanf("%s",p[j]);
        }
        return;
    }
    //---------------------------------------------------
    void outputString(char (*p)[80], int row)
    {
        // TODO
        int j;
        for(j=0 ; j<row; j++){
            char endChar = p[j][strlen(p[j])-1];
            printf("str[%d] = %s %c %c\n",j,p[j],p[j][0],endChar);
        }
        return;
    }
#endif // MY_SOL
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
#ifdef REF_SOL
#include <stdio.h>
#include <string.h>
void inputString(char (*p)[80], int row);
void outputString(char (*p)[80], int row);
int main()
{
	char word[5][80];
	int row;
	row = sizeof(word)/sizeof(word[0]); // 행의 개수 구하기
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
	int j;
    for(j=0 ; j<row; j++){
        sizt_t len = p[j];
        printf("str[%d] = %s %c %c\n",j,p[j],p[j][0],p[j][len-1]);
    }
	return;
}
#endif // REF_SOL





