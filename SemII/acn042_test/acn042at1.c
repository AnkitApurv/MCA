/*to write 5 words to file in parent, to read the words and sort them in child*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	char flP[7]="f1.txt";
	int i;
	char wP[5][5] = {'\0'};
	for(i=0; i<=4; i++)
		scanf("%5s", wP[i]);
	pid_t k = fork();
	if(k < 0)
		return -1;
	else if(k > 0)	//parent
	{
		int i;
		//char wP[5][5];
		FILE* fP = fopen(flP, "a");
		if(fP < 0) return -1;
		for(i=0; i<=4; i++)
		{
			//scanf("%5s", wP[i]);
			fprintf(fP, wP[i]);
			fprintf(fP, '\n');
		}
		fclose(fP);
		wait(NULL);
	}
	else	//child
	{
		int i, j;
		char wC[5][5] = {'\0'};
		FILE* fC = fopen(flP, "r");
		if(fC < 0) return -1;
		printf("Original order :\n");
		for(i=0; i<=4; i++)
		{
			fscanf(fC, wC[i]);
			printf("%5s\n", wC[i]);
		}
		char* temp;
		printf("Sorted order :\n");
		for(i=0; i<=4; i++)
		{
			for(j=0; j<4; j++)	//bubble sort words using strcmp()
			{
				if(strcmp(wC[j], wC[j+1]) > 0)
				{
					temp = *wC[j];
					*wC[j] = *wC[j+1];
					*wC[j+1] = temp;
				}
			}
			printf("%5s\n", wC[i]);
		}
		fclose(fC);
	}
	return 0;
}
