#include <stdio.h>
#include <stdlib.h>

#define max 2000

int n, m;
int v[max];
int find = 0;

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* arr[max];

void addEdge(int from, int to) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->to = to;
    node->next = arr[from];
    arr[from] = node;
}

void dfs(int node, int depth) {
    if (depth == 5) {
        find = 1;
        return;
    }
    v[node] = 1;

    for (Node* p = arr[node]; p != NULL; p = p->next) {
        if (!v[p->to]) {
            dfs(p->to, depth + 1);
            if (find) return;
        }
    }

    v[node] = 0;
}

int main(void) {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            v[j] = 0;
        }
        
        dfs(i, 1);
        if (find){
            break;
        }
    }

    printf("%d", find);

    return 0;
}
