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
    #include <stdlib.h>

    void initArray(int (*p)[4], int row);
    void outputArray(int (*p)[4], int row);

    int main()
    {
        int  num[3][4];
        int row;
        row = sizeof(num)/sizeof(num[0]); // 행의 개수 구하기
        initArray(num, row);
        outputArray(num, row);

        getchar();
        getchar();
        return 0;
    }
    //---------------------------------------------------
    void initArray(int (*p)[4], int row)
    {
            // TODO
        int i,j;
        for(i=0; i<row ; i++){
            for(j=0; j<4; j++){
                p[i][j] = rand()%20 + 1;
            }
        }
        return;
    }
    //---------------------------------------------------
    void outputArray(int (*p)[4], int row)
    {
        // TODO
        int i,j;
        int sum_row, sum_col;
        for(i=0; i<row ; i++){
            printf("%5d행 : ",i);
            sum_row = 0;
            for(j=0; j<4; j++){
                sum_row += p[i][j];
                printf("%5d",p[i][j]);
            }
            printf("%   2d행의 합 : %3d\n",i,sum_row);
        }

        printf("열의 합 :");
        for(j=0; j<4; j++){
            sum_col = 0;
            for(i=0; i<row; i++){
                sum_col += p[i][j];
            }
            printf("%5d",sum_col);
        }

        return;
    }

#endif // MY_SOL
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
#ifdef REF_SOL
#include <stdio.h>
#include <stdlib.h>

void initArray(int (*p)[4], int row);
void outputArray(int (*p)[4], int row);

int main()
{
	int  num[3][4];
	int row;
	row = sizeof(num)/sizeof(num[0]); // 행의 개수 구하기
	initArray(num, row);
	outputArray(num, row);

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void initArray(int (*p)[4], int row)
{
        // TODO
	return;
}
//---------------------------------------------------
void outputArray(int (*p)[4], int row)
{
	// TODO
	return;
}

#endif // REF_SOL




