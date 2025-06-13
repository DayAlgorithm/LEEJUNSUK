#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int heap[MAX];
int size = 0;


int hi(int a, int b) {
    int ma = a < 0 ? -a : a;
    int mb = b < 0 ? -b : b;

    if (ma != mb) {
        return ma < mb;
    }
    return a < b;  
}


void push(int x) {
    heap[++size] = x;
    int cur = size;

    while (cur > 1 && hi(heap[cur], heap[cur / 2])) {
        int temp = heap[cur];
        heap[cur] = heap[cur / 2];
        heap[cur / 2] = temp;
        cur /= 2;
    }
}

int pop() {
    if (size == 0){
        return 0;
    } 

    int ret = heap[1];
    heap[1] = heap[size--];

    int cur = 1;
    while (1) {
        int left = cur * 2;
        int right = cur * 2 + 1;
        int next = cur;

        if (left <= size && hi(heap[left], heap[next])) {
            next = left;
        }
        if (right <= size && hi(heap[right], heap[next])) {
            next = right;
        }

        if (next == cur) {
            break;
        }

        int temp = heap[cur];
        heap[cur] = heap[next];
        heap[next] = temp;
        cur = next;
    }

    return ret;
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", pop());
        } 
        else {
            push(x);
        }
    }

    return 0;
}
