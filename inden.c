#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int c=1;

int isOperator(char c) {
    char op[100] = {'+','-','*','=','/','%',';','(',')','{','}','[',']'};
    for(int i=0;i<strlen(op);i++) {
        if(c==op[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[1024];
    scanf("%[^\n]s", str);
    for(int i=0;i<strlen(str);i++) {
        if(isOperator(str[i])) {
            c++;
            str[i] = ' ';
        }
    }
    char filter[1024];
    int f=0;
    FILE *fp = fopen("in.c", "w+");
    for(int i=0;i<strlen(str);i++) {
        fputc(str[i], fp);
    }
    printf("%d", c);
    return 0;
}