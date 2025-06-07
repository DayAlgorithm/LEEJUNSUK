#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int N, M;
int degree[MAX] = {0};     
int g[MAX][MAX];      
int semester[MAX];          

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}
int dequeue() {
    return queue[front++];
}
int is_empty() {
    return front == rear;
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][b] = 1;
        degree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            enqueue(i);
            semester[i] = 1;
        }
    }


    while (!is_empty()) {
        int cur = dequeue();

        for (int i = 1; i <= N; i++) {
            if (g[cur][i]) {
                degree[i]--;
                if (semester[i] < semester[cur] + 1)
                    semester[i] = semester[cur] + 1;
                if (degree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }


    for (int i = 1; i <= N; i++) {
        printf("%d ", semester[i]);
    }

    return 0;
}
