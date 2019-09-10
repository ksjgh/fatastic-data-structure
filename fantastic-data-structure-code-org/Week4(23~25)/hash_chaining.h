#ifndef HASH_CHAINING_H_
#define HASH_CHAINING_H_

#define FALSE (0)
#define TRUE (1)
#define HASH_SIZE (10) /* �ؽ� ���̺��� size */

typedef int BOOL;

typedef struct _node{
	int key;
	struct _node *next;
}Node;

typedef struct _chaining_hash {
	Node *hash;   /* Node���·� ����Ǵ� �ؽ����̺� */
	int size;     /* hash tableũ�� (bucket ũ��) */
	int dataCnt;  /* hash table���� �������� ���� */
}CHash;

BOOL createHash(CHash *hp, int size);		/* �ؽ� ���� �� �ʱ�ȭ �Լ� */
int hashFunction(CHash *hp, int key);		/* �ؽð� ��� �Լ� */
BOOL hashInput(CHash *hp, int iData);	    /* �ؽÿ� ������ ���� �� */
int hashSearch(CHash *hp, int sData);	    /* �ؽÿ��� �����͸� ã�� */
BOOL hashDelete(CHash *hp, int dData);	    /* �ؽÿ� ������ ���� �� */
void destroyHash(CHash *hp);				/* �ؽ� �Ҹ� �Լ� */
void hashPrint(CHash *hp);                  /* �׽�Ʈ�� �Լ� - �ؽ� ���̺��� ���� ��� */

#endif /* HASH_CHAINING_H_ */
