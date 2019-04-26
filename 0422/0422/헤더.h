#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 50
#define DATALENGTH 1000

//���� ������ ����
typedef struct
{
	char word[LENGTH];	
	char speech[LENGTH];	
	char meaning[LENGTH];	
}element;

//����� ����
typedef struct treeNode {
	element key;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
}treeNode;



//void read(treeNode* root);//������ �о���� �Լ�
//int size();//�ܾ��� ������ ����ϴ� �Լ�
treeNode* find(treeNode* root, element x);
void insertNode(treeNode **root, element x);
void remove(treeNode **root, element x);
void print(treeNode* i);
void removeall(treeNode* root);


void insertNode(treeNode **root, element x);
void display(treeNode* root);