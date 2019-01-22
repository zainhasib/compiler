#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("Enter the code : ");
    char str[1024];
    scanf("%[^\n]s", str);
    for(int i=0;i<strlen(str);i++) {
        if((int)str[i]>=(int)'0' && (int)str[i]<=(int)'9') {
            printf("%c", str[i]);
        }
    }
    return 0;
}