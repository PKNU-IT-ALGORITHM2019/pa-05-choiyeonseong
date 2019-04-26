#include"헤더.h"

int main(void) {

	char command[LENGTH];
	element e;
	treeNode* root = NULL;
	int N = 0;//전체 단어의 개수


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

		//단어의 개수
		if (strcmp(command, "size") == 0) printf("size:%d",N);

		//단어의 설명 출력
		else if (strcmp(command, "find") == 0) { 
			
			scanf("%s", &e.word);

			print(find(root,e)); }
			

		//단어, 품사, 의미(word,class,meaning)
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
	

		//트리로부터 삭제
		else if (strcmp(command, "delete") == 0) { 
			
			gets_s(e.word);
			remove(&root, e);
			N--;
		}

		//파일을 열어서 삭제
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