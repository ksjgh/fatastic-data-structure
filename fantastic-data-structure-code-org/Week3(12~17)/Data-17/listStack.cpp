#include "listStack.h"
#include <stdio.h>
#include <malloc.h>
/*--------------------------------------------------------------------------------------
Function name	: createStack - ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
--------------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	sp->head = (Snode *)calloc(1, sizeof(Snode)); /* ��� ��� ����	*/
	if (sp->head == NULL) {
		return FALSE;
	}
	sp->tail = (Snode *)calloc(1, sizeof(Snode)); /* ���� ��� ���� */
	if (sp->tail == NULL) {
		free(sp->head);
		return FALSE;
	}
	/* ����尡 ���ϳ�带, ���ϳ�尡 ���ϳ�带 ����Ű�� �� */
	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: isStackEmpty() - ������ ����ִ°� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isStackEmpty(const Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}

	if (sp->head->next == sp->tail)
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push() - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  pushData  - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, char pushData)
{
	Snode *cur;			/* �۾��� Snode ������ ���� */
	if (sp == NULL) {	/* sp������ NULL check*/
		return FALSE;
	}

	cur = (Snode *)calloc(1, sizeof(Snode));	/* ���ο� ��� ���� */
	if (cur == NULL){		/* �޸� �Ҵ� �����ϸ� push���� */
		return FALSE;
	}
	else {					/* �� ��带 head node �ٷ� �ڿ� ��� �߰� */
		cur->next = sp->head->next;
		sp->head->next = cur;
		cur->data = pushData; /* �� ����� ������ ������ ������ ���� */
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop() - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack *sp, char *popData)
{
	Snode *cur;			/* �۾��� Snode ������ ���� */
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp) == TRUE){	/* stack�� ��������� pop���� */
		return FALSE;
	}
	else {		/* head node �ڿ��� �����͸� ���� �� ������ ��� ���� */
		*popData = sp->head->next->data;
		cur = sp->head->next;
		sp->head->next = sp->head->next->next;
		free(cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sp)
{
	Snode *cur;			/* �۾��� Snode ������ ���� */
	if (sp == NULL) {	/* sp������ NULL check*/
		return;
	}

	if (isStackEmpty(sp) == TRUE)
	{
		printf("Stack�� ����ֽ��ϴ�!!\n");
		return;
	}
	cur = sp->head->next;
	while (cur != sp->tail)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack() - ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	Snode *cur;			/* �۾��� Snode ������ ���� */
	if (sp == NULL) {	/* sp������ NULL check*/
		return;
	}
	/* ������ ù ������ �� ���� ������ ��� ���� */
	while (sp->head->next != sp->tail)
	{
		cur = sp->head->next;
		sp->head->next = sp->head->next->next;
		free(cur);
	}
	free(sp->head);	/* ����� ���� */
	free(sp->tail);	/* ���ϳ�� ���� */
	sp->head = sp->tail = NULL; /* head, tail �����͸� NULL�� �ʱ�ȭ */

	return;
}
