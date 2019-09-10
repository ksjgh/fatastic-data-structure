#pragma once
enum BOOL { FALSE, TRUE };

typedef struct _stack {
	int *stack;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	int size;		/* ������ ũ��(size) */
	int top;		/* ������ ��,�ⱸ ��ġ���� ���� */
}Stack;

BOOL createStack(Stack *, int);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
BOOL isStackFull(Stack *sPtr);		/* ������ �� ���ִ��� �˻� */
BOOL isStackEmpty(Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
BOOL push(Stack *, int);			/* ���ÿ� ������ �����ϴ� �Լ� */
BOOL pop(Stack *, int *);			/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*);		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *);			/* ���� �޸� ���� �Լ� */
