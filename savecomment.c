#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp=fopen("check.c", "r+");
    char output[1024];
    int o=0;
    char ch;
    while((ch=fgetc(fp))!=EOF) {
        output[o++] = ch;
    }
    char filterOutput[1024];
    int u=0;
    int stop=0;
    for(int i=0;i<strlen(output);i++) {
        if(output[i]=='/' && output[i+1]=='*') {
            i+=2;
            stop=1;
        }else if(output[i]=='*' && output[i+1]=='/') {
            stop=0;
            i+=2;
        }
        if(stop==0) {
            u+=sprintf(filterOutput+u, "%c", output[i]);
        }
    }
    printf("%s\n", filterOutput);
    fclose(fp);
    return 0;
}