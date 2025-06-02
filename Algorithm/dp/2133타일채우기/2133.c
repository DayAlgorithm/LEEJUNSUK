#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if (n % 2 == 1) {
        printf("0\n");
        return 0;
    }

    int dp[31] = {0};
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
