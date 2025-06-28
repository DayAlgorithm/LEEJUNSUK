#include <stdio.h>
#include <stdlib.h>

#define MAX 21
#define INF 1000000000

int t, n, b;
int staff[MAX];
int min_diff;

void dfs(int index, int sum) {
    if (sum >= b) {
        if (sum - b < min_diff) {
            min_diff = sum - b;
        }
        return;
    }
    if (index == n) return;

    dfs(index + 1, sum + staff[index]);
    dfs(index + 1, sum);
}

int main(void) {
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &b);

        for (int i = 0; i < n; i++) {
            scanf("%d", &staff[i]);
        }

        min_diff = INF;
        dfs(0, 0);

        printf("%d\n", min_diff);
    }

    return 0;
}
