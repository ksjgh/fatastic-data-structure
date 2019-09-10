#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singlyLinkedlist.h"

BOOL dataFileLoad(List *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ����
/*----------------------------------------------------------------------------------
  �Լ��� : main()
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
        printf("%2d��° �ܾ� : %s\n", tot_wCnt, curp->data);
        curp = curp->next;
    }

    printf("\n��ü �ܾ��� ���� : %3d\t\t ��� �ܾ� ���� %.2lf\n", tot_wCnt, (double)tot_length/tot_wCnt);

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
//            printf("%d��° �ܾ�:%s\n",i,curp->data);
//            sumOfWordLength += strlen(curp->data);
//            curp = curp->next;
//        }
//        printf("\n\n��ü �ܾ��� ���� : %i  ��� �ܾ� ���� : %.2f\n", lp->size, ((float)sumOfWordLength)/((float)lp->size) );

//    }

//    getchar();
//    return 0;
//}

/*----------------------------------------------------------------------------------
  �Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
BOOL dataFileLoad(List *lp) // ������ ���ϳ��� �����͸� ����Ʈ�� ����
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
        resp=searchNode(lp, word);  // ��ũ�帮��Ʈ ���� �ش� �ܾ �ִ� �� �˻�
        if(resp == NULL)     // �˻��� �ܾ ��ũ�帮��Ʈ ���� ������ �ܾ� ���� ���
            addLast(lp, word);
    }
    fclose(fp);
    return TRUE;
}
