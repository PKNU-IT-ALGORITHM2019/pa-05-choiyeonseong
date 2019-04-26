#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 50
#define DATALENGTH 1000

//사전 데이터 형식
typedef struct
{
	char word[LENGTH];	
	char speech[LENGTH];	
	char meaning[LENGTH];	
}element;

//노드의 구조
typedef struct treeNode {
	element key;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
}treeNode;



//void read(treeNode* root);//파일을 읽어오는 함수
//int size();//단어의 개수를 출력하는 함수
treeNode* find(treeNode* root, element x);
void insertNode(treeNode **root, element x);
void remove(treeNode **root, element x);
void print(treeNode* i);
void removeall(treeNode* root);


void insertNode(treeNode **root, element x);
void display(treeNode* root);