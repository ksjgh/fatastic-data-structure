#pragma once
enum BOOL{ FALSE, TRUE };

typedef struct _stacknode Snode;

struct _stacknode
{
	char data;		/* char ������ ���� */
	Snode *next;	/* ���� ��带 ����Ű�� ������ ���� */
};

typedef struct _stack	/* stack ���� ����ü */
{
	Snode *head;	/* head pointer (head node ����Ŵ) */
	Snode *tail;	/* tail pointer (tail node ����Ŵ) */
}Stack;

BOOL createStack(Stack *sp);		/* ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ� */
BOOL isStackEmpty(const Stack *sp);		/* ������ ������ ����ִ°� �˻� */
BOOL push(Stack *sp, char pushData);	/* ���ÿ� ������ �����ϴ� �Լ� */
BOOL pop(Stack *sp, char *popData);	/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*sp);		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *sp);			/* ���� �޸� ���� �Լ� */
