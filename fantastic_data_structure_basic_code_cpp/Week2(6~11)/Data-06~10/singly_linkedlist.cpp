#define MY_SOL
//#define REF_SOL

#ifdef MY_SOL
#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	// TODO
	if(lp==NULL) return FALSE;

	lp->head = (Node *)malloc(sizeof(Node));
	if(lp->head==NULL) return FALSE;

	lp->tail = (Node *)malloc(sizeof(Node));
	if(lp->tail==NULL){
        free(lp->head);
        return FALSE;
	}

	lp->head->next = lp->tail;
    lp->tail->next = lp->tail;
	lp->size = 0;

	return TRUE; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	// TODO
	if(lp==NULL) return FALSE;

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode==NULL)
        return FALSE;

	newNode->data = data;
	newNode->next = lp->head->next;
	lp->head->next = newNode;

	++lp->size;

	return TRUE; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	// TODO
	Node* newp;
	Node* btp; //before tail pointer

	if(lp==NULL) return FALSE;
	newp = (Node*)malloc(sizeof(Node));

	if(newp != NULL){
        newp->data = data;
        newp->next = lp->tail;

        //************************************
        // find node before tail node
        btp = lp->head;
        while(btp->next != lp->tail){
            btp = btp->next;
        }
        btp->next = newp;
        //************************************

        ++lp->size;
        return TRUE;
	}
	else {
        return FALSE;
	}
	//return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	// TODO
	if(lp == NULL) return;

	Node* cp;

	//************************************
	cp = lp->head->next;
	while(cp != lp->tail){
        printf("%8d\n",cp->data);
        cp = cp->next;
	}
	//************************************
	return;
}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	// TODO
	if(lp == NULL) return NULL;

	Node* curp;
	curp = lp->head->next;
	while(curp != lp->tail){
        if(curp->data == data ){
            return curp;
        }
        else{
            curp = curp->next;
        }
	}

	return NULL;

	//return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, int data)
{
	// TODO
	if(lp == NULL) return FALSE;

	Node* curp;
	Node* rp;

	rp = searchNode(lp, data);
	if(rp==NULL){
        return FALSE;
	}
	else{
        curp = lp->head;
        while(curp->next != rp){
            curp = curp->next;
        }
        curp->next = rp->next;
        free(rp);
        --lp->size;
        return TRUE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	// TODO
    Node* curp;
    Node* nextp;
    int temp;
    if(lp==NULL) return;

    curp = lp->head->next;
    while(curp->next != lp->tail ){
        nextp = curp->next;
        while(nextp != lp->tail){
            if(curp->data > nextp->data){
                temp = curp->data;
                curp->data = nextp->data;
                nextp->data = temp;
            }
            nextp = nextp->next;
        }
        curp = curp->next;
    }
}

/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	// TODO
    Node* curp;
    Node* nextp;
    if(lp==NULL) return;

    curp = lp->head->next;
    while(curp != lp->tail){
        nextp = curp->next;
        free(curp);
        curp = nextp;
    }

    free(lp->head);
    free(lp->tail);

    lp->head = NULL;
    lp->tail = NULL;
    lp->size = 0;
}
#endif // MY_SOL



///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////



#ifdef REF_SOL
#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	// TODO

	return;
}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	// TODO

	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	// TODO

	return;
}
#endif // REF_SOL
