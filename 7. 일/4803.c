#include <stdio.h>
#include <stdlib.h>

#define MAX 501

int n, m;
int adj[MAX][MAX];
int visited[MAX];

int isCycle(int curr, int parent) {
    visited[curr] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[curr][i]) {
            if (!visited[i]) {
                if (isCycle(i, curr)){
                    return 1;   
                }
            } else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int t = 1;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }

        int treeCount = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (!isCycle(i, 0)) {
                    treeCount++;
                }
            }
        }

        printf("Case %d: ", t++);
        if (treeCount == 0) {
            printf("No trees.\n");
        } else if (treeCount == 1) {
            printf("There is one tree.\n");
        } else {
            printf("A forest of %d trees.\n", treeCount);
        }
    }

    return 0;
}
