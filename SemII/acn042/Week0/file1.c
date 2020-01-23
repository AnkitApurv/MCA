#include<stdio.h>
int main(void)
{
    FILE *fp;
    char ch;
    fp= fopen("two.txt","w");
    printf("Enter the data");
    while(ch = getchar() != "0") {
        putc(ch,fp);
    }
    fclose(fp);
    fp=fopen("two.txt","r");
    while((ch = getc(fp)) != EOF )
    printf("%c",ch);
    fclose(fp);
    return 0;
}
