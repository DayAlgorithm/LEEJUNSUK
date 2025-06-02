#include<stdio.h>
#include<string.h>
int main(void){
    char stack[1000001];
    char str[1000001];
    int top = 0;

    scanf("%s",str);
    int len  = strlen(str);

    for(int i = 0; i<len; i++){
        stack[top++] = str[i];

        if(top>=4 && stack[top-4]=='P' && stack[top-3]=='P' && stack[top-2]=='A' && stack[top-1]=='P'){
            top -= 3;
        }
    }
    if(top == 1 && stack[0]=='P'){
        printf("PPAP");
    }
    else{
        printf("NP");
    }





    return 0;
}