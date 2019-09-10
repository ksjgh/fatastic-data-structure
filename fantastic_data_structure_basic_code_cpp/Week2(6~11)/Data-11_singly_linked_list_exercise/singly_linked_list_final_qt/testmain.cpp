#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singlyLinkedlist.h"

BOOL dataFileLoad(List *lp); // 데이터 파일내의 데이터를 리스트에 저장
/*----------------------------------------------------------------------------------
  함수명 : main()
----------------------------------------------------------------------------------*/
// reference solution
int main()
{
    List list;
    size_t tot_length=0;
    int tot_wCnt=0;
    Node* curp;
    BOOL bres;

    bres = createList(&list);
    // ****************************** //
    if(bres==FALSE){
        printf("list create error\n");
        getchar();
        return 0;
    }

    bres = dataFileLoad(&list);
    // ****************************** //
    if(bres==FALSE){
        printf("data file load error\n");
        getchar();
        return 0;
    }

    sortList(&list);

    curp = list.head->next;
    while( curp != list.tail ){
        tot_length += strlen( curp->data );
        tot_wCnt++;
        printf("%2d번째 단어 : %s\n", tot_wCnt, curp->data);
        curp = curp->next;
    }

    printf("\n전체 단어의 개수 : %3d\t\t 평균 단어 길이 %.2lf\n", tot_wCnt, (double)tot_length/tot_wCnt);

    // ****************************** //
    destroyList(&list);

    getchar();
    return 0;

}

//// my solution
//int main()
//{
//    // TODO
//    List* lp;
//    Node* curp;
//    int sumOfWordLength=0;


//    lp = (List*)malloc(sizeof(List));
//    if( createList(lp) )
//    {
//        dataFileLoad(lp);
//        sortList(lp);
////        displayList(lp); // check for sort

//        // print words
//        curp = lp->head->next;
//        for(int i=0; i<lp->size; i++)
//        {
//            printf("%d번째 단어:%s\n",i,curp->data);
//            sumOfWordLength += strlen(curp->data);
//            curp = curp->next;
//        }
//        printf("\n\n전체 단어의 개수 : %i  평균 단어 길이 : %.2f\n", lp->size, ((float)sumOfWordLength)/((float)lp->size) );

//    }

//    getchar();
//    return 0;
//}

/*----------------------------------------------------------------------------------
  함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
BOOL dataFileLoad(List *lp) // 데이터 파일내의 데이터를 리스트에 저장
{
    FILE *fp;
    char word[80];
    Node *resp;   

    fp=fopen("D:\\temp\\singly_linked_list_final_qt\\flower.txt", "rt");
//    fp=fopen("flower.txt", "rt");

    if(fp==NULL)
    {
        printf("File Open Error , Check file path\n");
        return FALSE;
    }

    while(fscanf(fp, "%s", word)!=EOF)
    {
        resp=searchNode(lp, word);  // 링크드리스트 내에 해당 단어가 있는 가 검사
        if(resp == NULL)     // 검사한 단어가 링크드리스트 내에 없으면 단어 새로 등록
            addLast(lp, word);
    }
    fclose(fp);
    return TRUE;
}
