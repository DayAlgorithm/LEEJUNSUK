#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51
#define aa 1000000

int n;
int graph[MAX][MAX];
int dist[MAX];
int score[MAX];

void bfs(int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 1; i <= n; i++) {
        dist[i] = aa;
    }

    dist[start] = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int now = queue[front++];

        for (int i = 1; i <= n; i++) {
            if (graph[now][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[now] + 1;
                queue[rear++] = i;
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (i != start && dist[i] != aa) {
            if (dist[i] > maxDist) {
                maxDist = dist[i];
            }
        }
    }

    score[start] = maxDist;
}

int main() {
    scanf("%d", &n);

    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1) break;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    int minScore = aa;
    for (int i = 1; i <= n; i++) {
        if (score[i] < minScore) {
            minScore = score[i];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (score[i] == minScore) cnt++;
    }

    printf("%d %d\n", minScore, cnt);
    for (int i = 1; i <= n; i++) {
        if (score[i] == minScore) {
            printf("%d ", i);
        }
    }

    return 0;
}
