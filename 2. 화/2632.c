#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int T, n, m;
int A[1000], B[1000];
int Asum[2000000], Bsum[2000000];
int Acnt = 0, Bcnt = 0;

void makesum(int* arr, int len, int* sumArr, int* sumCnt) {
    for (int i = 0; i < len; i++) {
        int sum = 0;
        for (int j = 0; j < len - 1; j++) {
            sum += arr[(i + j) % len];
            sumArr[(*sumCnt)++] = sum;
        }
    }

    int total = 0;
    for (int i = 0; i < len; i++)
        total += arr[i];
    sumArr[(*sumCnt)++] = total;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int upper(int* arr, int size, int target) {
    int left = 0, right = size, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int lower(int* arr, int size, int target) {
    int left = 0, right = size, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main(void) {
    scanf("%d", &T);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    makesum(A, n, Asum, &Acnt);
    makesum(B, m, Bsum, &Bcnt);

    qsort(Asum, Acnt, sizeof(int), compare);
    qsort(Bsum, Bcnt, sizeof(int), compare);

    long long ans = 0;

    for (int i = 0; i < Acnt; i++) {
        int target = T - Asum[i];
        int low = lower(Bsum, Bcnt, target);
        int high = upper(Bsum, Bcnt, target);
        ans += (high - low);
    }

    int aonly = lower(Asum, Acnt, T);
    int ahigh = upper(Asum, Acnt, T);
    ans += (ahigh - aonly);

    int bonly = lower(Bsum, Bcnt, T);
    int bhigh = upper(Bsum, Bcnt, T);
    ans += (bhigh - bonly);

    printf("%lld\n", ans);
    return 0;
}
