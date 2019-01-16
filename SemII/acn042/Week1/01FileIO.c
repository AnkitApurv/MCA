/*  author ankit apurv
	week 1 14/01/19
	desc to perform file copy ops using file related system calls
*/

#include <stdio.h>

int main(void)
{
	FILE* f1 = fopen("/tmp/t1.txt", "a");
	fputs("first line of text\n", f1);
	fclose(f1);

	FILE* f2 = fopen("/tmp/t2.txt", "a+");
	FILE* f0 = fopen("/tmp/t1.txt", "r");
	char buff[19];
	fgets(buff, 20, f0);
	fclose(f0);

	fputs(buff, f2);
	fgets(buff, 20, f2);
	fclose(f2);

	printf("%s", buff);
	return 0;
}
