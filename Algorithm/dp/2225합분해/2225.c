#include <stdio.h>

#define d 1000000000

int dp[201][201];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++){
        dp[i][1] = 1;
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[j][i] = (dp[j][i] + dp[j - l][i - 1]) % d;
            }
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}
