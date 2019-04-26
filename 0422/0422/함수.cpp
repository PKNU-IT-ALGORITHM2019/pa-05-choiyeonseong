#include "���.h"

treeNode* find(treeNode* root, element x) {
	//����Ž��Ʈ������ Ű���� x�� ����� ��ġ�� Ž��
	//p�� NULL�̸� �ݺ����� ����ؼ� ��ȸ�Ͽ� ã�´�

	while (root != NULL) {
		if (strcmp(x.word, root->key.word) == 0)
			return root;
		else if (strcmp(x.word, root->key.word) < 0)
			root = root->leftChild;
		else if (strcmp(x.word, root->key.word) > 0)
			root = root->rightChild;
	}
	printf("\n\tã�� �ܾ �����ϴ�.");
	return root;
}

void print(treeNode* i) {
	if (i ==NULL)
	{
		printf("ã�� �ܾ �����ϴ�.");
		return;
	}
	
	printf("word: %s\nclass: %s\nmeaning: %s",
		i->key.word,
		i->key.speech,
		i->key.meaning);
}


//element�� x�� �����ϴ� ����
void insertNode(treeNode **root, element x)
{
	treeNode *nNode;			//�����
	treeNode *qNode = NULL;		//������ �ڸ��� ã�� ���� ������ ����
	treeNode *pNode = *root;	//������ ����� �θ���

	while (pNode != NULL) {
		if (strcmp(x.word, pNode->key.word) == 0) {
		
			return;
		}

		qNode = pNode;

		if (strcmp(x.word, pNode->key.word) < 0) {
			//printf("\t �����ڽ����� �̵�\n");
			pNode = pNode->leftChild;
		}
		else if (strcmp(x.word, pNode->key.word) > 0) {
			//printf("\t �������ڽ����� �̵�\n");
			pNode = pNode->rightChild;
		}
	}

	//������ �ڸ��� ã������ ������ ��� ����
	nNode = (treeNode*)malloc(sizeof(treeNode));
	nNode->key = x;
	nNode->leftChild = NULL;
	nNode->rightChild = NULL;

	//������ �ڸ��� �θ���� �񱳳�带 ����
	if (qNode != NULL) {
		if (strcmp(x.word, qNode->key.word) < 0) {
			//printf("\t ���� �ڽĿ� ����");
			qNode->leftChild = nNode;
		}
		else if (strcmp(x.word, qNode->key.word) > 0) {
			//printf("\t ������ �ڽĿ� ����");
			qNode->rightChild = nNode;
		}
	}

	else {
		*root = nNode;	//����ִٸ� ���θ��� ��带 root��
	}
}


void remove(treeNode **root, element x) {

	//root������ Ž���Ͽ� key�������� ��带 ã�� ����
	treeNode *parent = NULL;	//�θ���
	treeNode *pNode = *root;	//������
	treeNode *child;			//�ڽĳ��
	treeNode *succ, *succ_parent;//�İ��ڳ�带 ���� ������

								 //������ ����� ��ġŽ��(���Զ��Ͱ���)
	while ((pNode != NULL) && (strcmp(x.word, pNode->key.word) != 0)) {
		parent = pNode;
		if (strcmp(x.word, pNode->key.word) < 0) {
			pNode = pNode->leftChild;
		}
		else {
			pNode = pNode->rightChild;
		}
	}

	//Ž����� pNode�� NULL�̴�. Ű�� ���ٴ¶�
	if (pNode == NULL) {
		printf("\n\tã�� Ű�� ����Ʈ���� �����ϴ�.\n");
		return;
	}

	//������ ó�� ����3���� - �ܸ�����ΰ��
	if ((pNode->leftChild == NULL) && (pNode->rightChild == NULL)) {
		if (parent != NULL) {				//�θ��尡 �����ϴ���Ȯ��
			if (parent->leftChild == pNode)	//�θ����� ������ ������ ����ΰ��
				parent->leftChild = NULL;
			else parent->rightChild = NULL;	//�θ����� �������� ������ ����ΰ��
		}
		else root = NULL;	//�θ��尡 ������ root=NULL
	}

	//������ ��尡 �� ���� �ڽ� ��带 ���� ���
	else if ((pNode->leftChild == NULL) || (pNode->rightChild == NULL)) {
		if (pNode->leftChild != NULL)	//������ ����� ������ �ڽĳ��� ����
			child = pNode->leftChild;
		else child = pNode->rightChild;	//������ ����� �������� �ڽĳ��� ����

		if (parent != NULL) {
			if (parent->leftChild == pNode)	//�θ��� ������ ��������
				parent->leftChild = child;	//�ڽĳ�带 �θ����� ���ʰ� ����

			else							//�θ��� �������� ��������
				parent->rightChild = child;	//�ڽĳ�带 �θ����� �����ʰ� ����									
		}
		else *root = child;	//������ ���� ���� �ڽĳ�� �ۿ� ���ٸ� root�� ����
	}

	//������ ��尡 �ΰ��� �ڽ� ��带 �������
	else {
		succ_parent = pNode;				//������ ��带 succ_parent�� ����
		succ = pNode->leftChild;			//���� ����Ʈ������ �İ��ڸ� ã�´�
		while (succ->rightChild != NULL) {	//�İ��ڸ� ã�Ƽ� ��� ���������� �̵�(������ ���� NULL�϶����� �ݺ�)
			succ_parent = succ;				//���� �񱳸� ���� Ž������ ����� �θ𰪵� ���� �̵�
			succ = succ->rightChild;		//���� ����Ʈ��(���� ������ ���), ������ ����Ʈ��(���� ���ʳ��)
		}

		//���� ����Ʈ������ ������ ���� ���� ��� ������ ����� ���ʳ�尡 �İ��ڰ� ��
		if (succ_parent->leftChild == succ)
			succ_parent->leftChild;
		else succ_parent->rightChild = succ->leftChild;//���õ� �İ����� ������ NULL�̹Ƿ� ���ʰ��� �θ��� �����ʿ� ����

		pNode->key = succ->key;	//�İ����� key���� ������ ����� key�� �־���
		pNode = succ;			//ã�� ���� ������ ����� ��ġ�� ����
	}
	free(pNode);


}

void removeall(treeNode* root) {
	FILE *fp;
	element e;
	char filename[LENGTH];
	int i = 0;

	scanf("%s", filename);

	fp = fopen(filename, "r");

	while (!feof(fp)) {

		fscanf(fp, "%s", e.word);
		remove(&root, e);

		i++;


	}
	fclose(fp);
}

void display(treeNode* root)
{
	int i;
	if (root != NULL) {
		display(root->leftChild);
	
		printf("\t %s :(%s) %s",
			root->key.word, root->key.speech , root->key.meaning);

		printf("\t\t\t[");
		for (i = 0; i <= LENGTH; i++) {
			if (root->key.word[i] == NULL) break;
			else printf("%d", root->key.word[i]);
		}printf("]\n");

		display(root->rightChild);
	}
}