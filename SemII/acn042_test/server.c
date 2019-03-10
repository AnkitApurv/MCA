/*server*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h> //memcpy()

int countWords(char* w) {
	int i = 0, countofWords = 1;
	while(s[i] != '\0')
		if(s[i] == ' ')
			countOfWords++;
	return countOfWords;
}

void sortWords(char* w) {
	int countOfWords = countWords(w);
	char words[countOfWords][10];
	int j, i = 0, word = 1;
	while(s[i] != '\0') {
		j = 0;
		while(s[i] != ' ') {
			s[i++] = words[word][j++];
		}
		word++;
	}
	int wordSize[countOfWords];
	for(i=0; i<countOfWords; i++) {
		wordSize[i] = 0;
		while(
	}
	return;
}

void sortWordsReverse(char* w) {
	int countOfWords = countWords(w);
	char words[countOfWords][10];
	
	return;
}

int main(void) {
	char s[100];
	const char begin = '$';
	key_t k = ftok(".", 68);
	int shmID = shmget(k, sizeof(char)*150, 0666 | IPC_CREAT);
	if(shmID < 0) return -1;
	char* shmBlk = shmat(shmID, NULL, 0);
	
	printf("recieving initial\n");
	while(*shmBlk != begin) { }
	printf("initial begin\n");
	memcpy(s, shmBlk, sizeof(s));
	printf("recieved\n\n");
	
	sortWords(s);
	printf("sending sorted\n");
	memcpy(shmBlk, &begin, sizeof(char));
	wait(0);
	memcpy(shmBlk, s, sizeof(s));
	printf("sent sorted\n\n");
	
	
	sortWordsReverse(s);
	printf("sending reverse sorted\n");
	memcpy(shmBlk, &begin, sizeof(char));
	wait(0);
	memcpy(shmBlk, s, sizeof(s));
	printf("sent reverse sorted\n\n");
	
	shmdt(shmBlk);
	return 0;	
}
