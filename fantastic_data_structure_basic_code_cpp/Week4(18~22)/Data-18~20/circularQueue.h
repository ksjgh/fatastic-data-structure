#pragma once 
enum BOOL { FALSE, TRUE };

typedef struct _queue {
	int *queue;
	int size;
	int front, rear;
}Queue;

BOOL createQueue(Queue * qp, int size);		/* ť ���� �� �ʱ�ȭ �Լ� */
BOOL isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
BOOL isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
BOOL enqueue(Queue * qp, int enqueData);	/* ť�� ������ �ϳ��� ���� �� */
BOOL dequeue(Queue * qp, int * dequeData);	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp);			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp);				/* ť �Ҹ� �Լ� */
