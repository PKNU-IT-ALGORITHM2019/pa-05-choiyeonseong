#include "헤더.h"

treeNode* find(treeNode* root, element x) {
	//이진탐색트리에서 키값이 x인 노드의 위치를 탐색
	//p가 NULL이면 반복중지 계속해서 순회하여 찾는다

	while (root != NULL) {
		if (strcmp(x.word, root->key.word) == 0)
			return root;
		else if (strcmp(x.word, root->key.word) < 0)
			root = root->leftChild;
		else if (strcmp(x.word, root->key.word) > 0)
			root = root->rightChild;
	}
	printf("\n\t찾는 단어가 없습니다.");
	return root;
}

void print(treeNode* i) {
	if (i ==NULL)
	{
		printf("찾는 단어가 없습니다.");
		return;
	}
	
	printf("word: %s\nclass: %s\nmeaning: %s",
		i->key.word,
		i->key.speech,
		i->key.meaning);
}


//element형 x를 삽입하는 연산
void insertNode(treeNode **root, element x)
{
	treeNode *nNode;			//새노드
	treeNode *qNode = NULL;		//삽입할 자리를 찾기 위한 포인터 변수
	treeNode *pNode = *root;	//삽입할 노드의 부모노드

	while (pNode != NULL) {
		if (strcmp(x.word, pNode->key.word) == 0) {
		
			return;
		}

		qNode = pNode;

		if (strcmp(x.word, pNode->key.word) < 0) {
			//printf("\t 왼쪽자식으로 이동\n");
			pNode = pNode->leftChild;
		}
		else if (strcmp(x.word, pNode->key.word) > 0) {
			//printf("\t 오른쪽자식으로 이동\n");
			pNode = pNode->rightChild;
		}
	}

	//삽입할 자리를 찾았으니 삽입할 노드 생성
	nNode = (treeNode*)malloc(sizeof(treeNode));
	nNode->key = x;
	nNode->leftChild = NULL;
	nNode->rightChild = NULL;

	//삽입할 자리의 부모노드와 비교노드를 연결
	if (qNode != NULL) {
		if (strcmp(x.word, qNode->key.word) < 0) {
			//printf("\t 왼쪽 자식에 저장");
			qNode->leftChild = nNode;
		}
		else if (strcmp(x.word, qNode->key.word) > 0) {
			//printf("\t 오른쪽 자식에 저장");
			qNode->rightChild = nNode;
		}
	}

	else {
		*root = nNode;	//비어있다면 새로만든 노드를 root로
	}
}


void remove(treeNode **root, element x) {

	//root노드부터 탐색하여 key값과같은 노드를 찾아 삭제
	treeNode *parent = NULL;	//부모노드
	treeNode *pNode = *root;	//현재노드
	treeNode *child;			//자식노드
	treeNode *succ, *succ_parent;//후계자노드를 구할 포인터

								 //삭제할 노드의 위치탐색(삽입때와같음)
	while ((pNode != NULL) && (strcmp(x.word, pNode->key.word) != 0)) {
		parent = pNode;
		if (strcmp(x.word, pNode->key.word) < 0) {
			pNode = pNode->leftChild;
		}
		else {
			pNode = pNode->rightChild;
		}
	}

	//탐색결과 pNode가 NULL이다. 키가 없다는뜻
	if (pNode == NULL) {
		printf("\n\t찾는 키가 이진트리에 없습니다.\n");
		return;
	}

	//삭제후 처리 종류3가지 - 단말노드인경우
	if ((pNode->leftChild == NULL) && (pNode->rightChild == NULL)) {
		if (parent != NULL) {				//부모노드가 존재하는지확인
			if (parent->leftChild == pNode)	//부모노드의 왼쪽이 삭제할 노드인경우
				parent->leftChild = NULL;
			else parent->rightChild = NULL;	//부모노드의 오른쪽이 삭제할 노드인경우
		}
		else root = NULL;	//부모노드가 없으면 root=NULL
	}

	//삭제할 노드가 한 개의 자식 노드를 가진 경우
	else if ((pNode->leftChild == NULL) || (pNode->rightChild == NULL)) {
		if (pNode->leftChild != NULL)	//삭제할 노드의 왼쪽을 자식노드로 연결
			child = pNode->leftChild;
		else child = pNode->rightChild;	//삭제할 노드의 오른쪽을 자식노드로 연결

		if (parent != NULL) {
			if (parent->leftChild == pNode)	//부모노드 왼쪽이 삭제노드면
				parent->leftChild = child;	//자식노드를 부모노드의 왼쪽과 연결

			else							//부모노드 오른쪽이 삭제노드면
				parent->rightChild = child;	//자식노드를 부모노드의 오른쪽과 연결									
		}
		else *root = child;	//삭제후 남은 값이 자식노드 밖에 없다면 root로 지정
	}

	//삭제할 노드가 두개의 자식 노드를 가진경우
	else {
		succ_parent = pNode;				//삭제할 노드를 succ_parent로 지정
		succ = pNode->leftChild;			//왼쪽 서브트리에서 후계자를 찾는다
		while (succ->rightChild != NULL) {	//후계자를 찾아서 계속 오른쪽으로 이동(오른쪽 값이 NULL일때까지 반복)
			succ_parent = succ;				//값의 비교를 위해 탐색중인 노드의 부모값도 같이 이동
			succ = succ->rightChild;		//왼쪽 서브트리(가장 오른쪽 노드), 오른쪽 서브트리(가장 왼쪽노드)
		}

		//왼쪽 서브트리에서 오른쪽 값이 없을 경우 삭제할 노드의 왼쪽노드가 후계자가 됨
		if (succ_parent->leftChild == succ)
			succ_parent->leftChild;
		else succ_parent->rightChild = succ->leftChild;//선택된 후계자의 오른쪽 NULL이므로 왼쪽값을 부모노드 오른쪽에 연결

		pNode->key = succ->key;	//후계자의 key값을 삭제할 노드의 key로 넣어줌
		pNode = succ;			//찾은 값을 삭제할 노드의 위치로 변경
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