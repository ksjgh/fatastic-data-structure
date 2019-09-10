#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

enum BOOL{FALSE, TRUE};
typedef struct _node Node;					/* 구조체 노드 형명재지정 */
struct  _node {								/* 노드 구조체 (자기참조 구조체 사용) */
    char data[80]; 							/* 데이터 영역 */
    Node *next;								/* 포인터 영역 */
};
typedef  struct  _list { 					/* 연결 리스트 관리 구조체 */
    Node *head;								/* head pointer (head node 가리킴) */
    Node *tail; 							/* tail pointer (tail node 가리킴) */
    int size;								/* 연결 리스트의 크기 - 실제 data node의 개수 */
}List;

BOOL createList(List *lp);					/* 연결 리스트 초기화 */
BOOL addFirst(List *lp, char *data);		/* head node 뒤에 node 추가(역순 저장) */
BOOL addLast(List *lp, char *data);			/* tail node 앞에 node 추가(정순 저장) */
void displayList(List *lp);					/* 리스트 내의 모든 데이터 출력 */
BOOL removeNode(List *lp, char *data);		/* data 노드 삭제 */
Node * searchNode(List *lp, char *data);	/* data와 일치하는 node 검색 */
void sortList(List *lp);					/* 노드 정렬 - 오름차순 */
void destroyList(List *lp);					/* 리스트 내의 모든 노드를 삭제 */


#endif // SINGLYLINKEDLIST_H
