#pragma once
enum BOOL{FALSE, TRUE};
typedef struct _node Node;				/* ����ü ��� ���������� */
struct  _node {							/* ��� ����ü (�ڱ����� ����ü ���) */
	int data; 							/* ������ ���� : int�� ������ ���� */
	Node *next;							/* ������ ���� */
};
typedef  struct  _list { 				/* ���� ����Ʈ ���� ����ü */
	Node *head;							/* head pointer (head node ����Ŵ) */
	Node *tail; 						/* tail pointer (tail node ����Ŵ) */
	int size;							/* ���� ����Ʈ�� ũ�� - ���� data node�� ���� */
}List;

BOOL createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
BOOL addFirst(List *lp, int data);			/* head node �ڿ� node �߰�(���� ����) */
BOOL addLast(List *lp, int data);			/* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp);					/* ����Ʈ ���� ��� ������ ��� */
BOOL removeNode(List *lp, int data);		/* data ��� ���� */
Node * searchNode(List *lp, int data);		/* data�� ��ġ�ϴ� node �˻� */
void sortList(List *lp);					/* ��� ���� - �������� */
void destroyList(List *lp);					/* ����Ʈ ���� ��� ��带 ���� */