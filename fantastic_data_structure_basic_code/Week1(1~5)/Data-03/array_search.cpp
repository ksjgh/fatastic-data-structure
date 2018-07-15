//#define MY_SOL
#define REF_SOL

#ifdef MY_SOL

#include <stdio.h>
#include <stdlib.h>
void printArray(int *ap, unsigned int cnt); // 배열내용 출력 함수
void initArray(int *ap, unsigned int size); // 1~20까지의 난수로 배열초기화하는 함수
int searchArray(int *ap, unsigned int size, int sData); // 검색함수

int main()
{
	int num[10];		// 데이터 저장 배열
	unsigned int size;  // 배열의 크기(방이 개수) 저장
	int sData;			// 검색할 데이터 저장
	int res=0;			// 검색 결과 저장
	int i;
	size = sizeof(num)/sizeof(num[0]);	// 배열 크기 계산

	initArray(num, size);
	printArray(num, size);

	for(i=0; i<5; i++){
		printf("# 검색할 정수를 입력하시오 : ");
		scanf("%d", &sData);
		res = searchArray(num, size, sData);
		if(res!=-1)
			printf("%d는 %d번 방에 있습니다.\n", sData, res);
		else
			printf("%d는 존재하지 않습니다.\n", sData);
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
	printf("배열의 내용 : ");
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
void printArray(int *ap, unsigned int cnt); // 배열내용 출력 함수
void initArray(int *ap, unsigned int size); // 1~20까지의 난수로 배열초기화하는 함수
int searchArray(int *ap, unsigned int size, int sData); // 검색함수

int main()
{
	int num[10];		// 데이터 저장 배열
	unsigned int size;  // 배열의 크기(방이 개수) 저장
	int sData;			// 검색할 데이터 저장
	int res=0;			// 검색 결과 저장
	int i;
	size = sizeof(num)/sizeof(num[0]);	// 배열 크기 계산

	initArray(num, size);
	printArray(num, size);

	for(i=0; i<5; i++){
		printf("# 검색할 정수를 입력하시오 : ");
		scanf("%d", &sData);
		res = searchArray(num, size, sData);
		if(res!=-1)
			printf("%d는 %d번 방에 있습니다.\n", sData, res);
		else
			printf("%d는 존재하지 않습니다.\n", sData);
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
	printf("배열의 내용 : ");
	for (i = 0; i < cnt; i++) {
		printf("%5d", *ap++);
	}
	printf("\n");
}
#endif // REF_SOL

