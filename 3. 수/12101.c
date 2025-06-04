#include <stdio.h>

int n, k;
int many = 0;
int pan = 0;
int path[11];

void findWays(int sum, int length) {
    if (pan) return;
    if (sum > n) return;

    if (sum == n) {
        many++;
        if (many == k) {
            for (int i = 0; i < length; i++) {
                if (i > 0) printf("+");
                printf("%d", path[i]);
            }
            printf("\n");
            pan = 1;
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        path[length] = i;
        findWays(sum + i, length + 1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    findWays(0, 0);
    if (!pan) {
        printf("-1\n");
    }
    return 0;
}
