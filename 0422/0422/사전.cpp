#include"���.h"

int main(void) {

	char command[LENGTH];
	element e;
	treeNode* root = NULL;
	int N = 0;//��ü �ܾ��� ����


	FILE *fp;
	char *pStr;
	char strTmp[DATALENGTH];

	fp = fopen("shuffled_dict.txt", "r");

	while (!feof(fp)) {

		pStr = fgets(strTmp, sizeof(strTmp), fp);

		fscanf(fp, "%[^,] (%[^,]) %[^,]",
			e.word,
			e.speech,
			e.meaning);

		insertNode(&root, e);

		N++;

	}
	fclose(fp);

	while (1) {
		printf("$ ");
		scanf("%s", &command);

		//�ܾ��� ����
		if (strcmp(command, "size") == 0) printf("size:%d",N);

		//�ܾ��� ���� ���
		else if (strcmp(command, "find") == 0) { 
			
			scanf("%s", &e.word);

			print(find(root,e)); }
			

		//�ܾ�, ǰ��, �ǹ�(word,class,meaning)
		else if (strcmp(command, "add") == 0) {

			N++;
			printf("word: ");
			gets_s(e.word);

			printf("class: ");
			gets_s(e.speech);

			printf("meaning: ");
			gets_s(e.meaning);
			
			insertNode(&root, e);
		}
	

		//Ʈ���κ��� ����
		else if (strcmp(command, "delete") == 0) { 
			
			gets_s(e.word);
			remove(&root, e);
			N--;
		}

		//������ ��� ����
		//$deleteall to_be_deleted_words.txt
		//1760 words were deleted successfully.
		else if (strcmp(command, "deleteall") == 0) {
			char filename[LENGTH];
			int i = 0;

			gets_s(filename);

			fp = fopen(filename, "r");

			while (!feof(fp)) {

				fgets(e.word,LENGTH, fp);
				remove(&root, e);

				i++;


			}
			fclose(fp);
			N = N - i;
			printf("%d words were deleted successfully.",i);
		}

		else if (strcmp(command, "exit") == 0)
			break;
		printf("\n");
	}
	
}