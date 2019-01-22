#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    FILE *fp = fopen("ex.c", "r");
    char str[1024];
    int s=0;
    char ch;
    if(fp!=NULL) {
        while((ch=fgetc(fp))!=EOF) {
            str[s++] = ch;
        }
        str[s] = '\0';
        char newString[1024];
        int ns=0;
        for(int i=0;i<strlen(str);i++) {
            if(str[i]==' ' && str[i+1]==' ') {

            } else {
                newString[ns++] = str[i];
            }
        }
        newString[ns] = '\0';
        FILE *fp2 = fopen("newfile.c", "w+");
        if(fp2!=NULL) {
            for(int i=0;i<strlen(newString);i++) {
                putc(newString[i], fp2);
            }
        }
    }
}
