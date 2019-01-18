#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp=fopen("check.c", "r+");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char output[1024];
    int d=0;
    if(fp!=NULL) {
        char ch;
        while ((read = getline(&line, &len, fp)) != -1) {
            for(int i=0;i<strlen(line);i++) {
                if(line[i]=='/' && line[i+1]=='/') { // Removes single line comment
                    break;
                }else {
                    d+=sprintf(output+d, "%c", line[i]);
                }
            }
        }
    }
    char filterOutput[1024];
    int u=0;
    int stop=0;
    for(int i=0;i<strlen(output);i++) { // Removes multiline comment
        if(output[i]=='/' && output[i+1]=='*') {
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