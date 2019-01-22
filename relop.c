#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* check(char *op) {
    switch(op[0]) {
        case '!':
            if(op[1]=='=') {
                return "NE";
            }else {
                return "NONE";
            }
            break;
        case '=':
            if(op[1]=='=') {
                return "EQ";
            }else {
                return "NONE";
            }
            break;
        case '<':
            if(op[1]=='=') {
                return "LE";
            }else {
                return "LT";
            }
            break;
        case '>':
            if(op[1]=='=') {
                return "GE";
            }else {
                return "GT";
            }
            break;
    }
}

int main() {
    printf("Enter the Relational Operator : ");
    char op[10];
    scanf("%s", op);
    if(strlen(op)>2) {
        printf("Dude!! Maar Khaoge!");
        return 0;
    }
    char* good = check(op);
    printf("%s\n", good);
    return 0;
}