#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
#include <string.h>

/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {  /* lp������ NULL check */
		return FALSE;
	}
	lp->head = (Node *)malloc(sizeof(Node));	/* head node ���� */
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (Node *)malloc(sizeof(Node));	/* tail node ���� */
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}

	lp->head->next = lp->tail; /* head node�� tail node ���� */
	lp->tail->next = lp->tail; /* tail node�� next�� �ڱ� �ڽ��� ����Ű���� ���� */
	lp->size = 0;	/* ���� ����Ʈ ũ�� 0���� �ʱ�ȭ */

	return TRUE;
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, char *data)
{
	Node *newp;

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)malloc(sizeof(Node)); 	/* �� ��� ���� */
	if (newp != NULL) {						/* �� ��� ���� ���� �� ó�� */
		strcpy(newp->data, data);			/* �� ��忡 data ���� */
		newp->next = lp->head->next; 		/* �� ����� next ���� */
		lp->head->next = newp;				/* head ndoe �ڿ� �� ��� ���� */
		++lp->size;							/* ����Ʈ size ���� */
		return TRUE;
	}
	else {									/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, char *data)
{
	Node *newp;	/* �� ��� �ּ������ ������ */
	Node *btp;	/* tail node �ٷ� �� ��带 ����Ű�� ������ */

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)malloc(sizeof(Node));	/* �� ��� ���� */
	if (newp != NULL) {	/*  �� ��� ���� ���� �� ó�� */
		strcpy(newp->data, data);	/* �� ��忡 data ���� */
		newp->next = lp->tail;	/* �� ����� next ���� */
		/* tail node�� �� ��� �˻� */
		btp = lp->head;
		while (btp->next != lp->tail) {  /* before tail pointer�� tail node �ٷ� �� ��带 ����Ű���� ��ġ ���� */
			btp = btp->next;
		}

		btp->next = newp;	/* tail node �տ� �� ��� ���� */
		++lp->size;	/* ����Ʈ size ���� */
		return TRUE;
	}
	else {	/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
}

/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	curp = lp->head->next;  /* data �ִ� ù��带 curp�� ����Ű�� �� */

	/* ����Ʈ�� ������ ������ curp�� �ű�鼭 data���� ����ϱ� */
	while (curp != lp->tail) {	
		printf("%s\n", curp->data);
		curp = curp->next;
	}

	printf("\n");

	return;
}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, char *data)
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
		return NULL;
	}

	curp = lp->head->next;  /* data �ִ� ù��带 curp�� ����Ű�� �� */
	/* ����Ʈ�� ������ ������ ������ curp�� �ű�鼭 �˻��ϱ� */
	while (curp != lp->tail) {
		if (strcmp(curp->data , data)==0) {
			return curp;	/* ã�� ����� �ּ� ���� */
		}
		else {
			curp = curp->next;
		}
	}

	return NULL;	/* ��ã���� NULL pointer ���� */
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, char *data)
{
	Node *delp;
	Node *curp;
	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}
	delp = searchNode(lp, data);  /* ������ node�� �˻� �� */
	if (delp != NULL) { /* ������ ��带 ã������ �����ϱ� */

		curp = lp->head; /* ������ ����� �ٷ� �� ��带 ã�� */
		while (curp->next != delp) {
			curp = curp->next;
		}

		curp->next = delp->next; /* ������ ����� �� ���� ������ ����� �� ��带 ����*/
		free(delp);	/* ��� ���� */
		--lp->size;	/* ����Ʈ size ���� */
		return TRUE;
	}
	else {	/* ������ ����� ��ã������ ���� ���� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *curp;
	Node *nextp;
	char temp[80];
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	curp = lp->head->next;
	while (curp->next != lp->tail) {
		nextp = curp->next;
		while (nextp != lp->tail) {
			if ( strcmp(curp->data , nextp->data)>0 ) {
				strcpy(temp , curp->data);
				strcpy(curp->data , nextp->data);
				strcpy(nextp->data , temp);
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}
	curp = lp->head->next;
	while (curp != lp->tail) {
		nextp = curp->next;
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}


