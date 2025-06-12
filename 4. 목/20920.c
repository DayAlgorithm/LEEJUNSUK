#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000
#define LEN 11

char word[MAX][LEN];
int count[MAX];       
int idx[MAX];         
int n, m;             
int total = 0;       

int cmp(const void* x, const void* y) {
    int i = *(int*)x;
    int j = *(int*)y;

    if (count[i] != count[j]) return count[j] - count[i];
    int len1 = strlen(word[i]);
    int len2 = strlen(word[j]);
    if (len1 != len2) return len2 - len1;
    return strcmp(word[i], word[j]);
}

int main() {
    scanf("%d %d", &n, &m);
    char temp[MAX][LEN]; 
    int tempSize = 0;

    for (int i = 0; i < n; i++) {
        char t[LEN];
        scanf("%s", t);
        if (strlen(t) >= m) {
            strcpy(temp[tempSize++], t);
        }
    }

    qsort(temp, tempSize, LEN, (int(*)(const void*, const void*))strcmp);

    for (int i = 0; i < tempSize; i++) {
        if (total > 0 && strcmp(word[total - 1], temp[i]) == 0) {
            count[total - 1]++;
        } else {
            strcpy(word[total], temp[i]);
            count[total++] = 1;
        }
    }

    for (int i = 0; i < total; i++) {
        idx[i] = i;
    }

    qsort(idx, total, sizeof(int), cmp);

    for (int i = 0; i < total; i++) {
        printf("%s\n", word[idx[i]]);
    }

    return 0;
}
