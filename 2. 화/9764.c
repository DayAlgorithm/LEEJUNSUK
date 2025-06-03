#include<stdio.h>

int dp[2001];

int main(void){
    int t;
    
    scanf("%d",&t);
    dp[0] = 1;

    for(int i=1; i<2001; i++){
        for(int j=2000; j>= i; j--){
            dp[j] = (dp[j]+dp[j-i]) % 100999;
        }
    }

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}