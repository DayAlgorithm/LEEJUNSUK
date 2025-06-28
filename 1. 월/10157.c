#include <stdio.h>

int main(void) {
    int c, r, k;
    scanf("%d %d", &c, &r);
    scanf("%d", &k);

    if (k > c * r) {
        printf("0\n");
        return 0;
    }

    int map[1001][1001] = {0};

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int x = 0, y = 0, dir = 0;
    for (int i = 1; i <= k; i++) {
        map[y][x] = i;

        if (i == k) {
            printf("%d %d\n", x + 1, y + 1);
            return 0;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= c || ny >= r || map[ny][nx] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    return 0;
}
