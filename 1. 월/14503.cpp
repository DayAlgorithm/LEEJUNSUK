#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[50][50];
bool cleaned[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, dir;
    cin >> n >> m >> x >> y >> dir;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int cnt = 0;
    while (true) {
        if (!cleaned[x][y]) {
            cleaned[x][y] = true;
            cnt++;
        }
        bool moved = false;
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && !cleaned[nx][ny]) {
                x = nx; y = ny;
                moved = true;
                break;
            }
        }
        if (moved) continue;
        int back = (dir + 2) % 4;
        int bx = x + dx[back], by = y + dy[back];
        if (bx < 0 || bx >= n || by < 0 || by >= m || a[bx][by] == 1) break;
        x = bx; y = by;
    }

    cout << cnt << "\n";
    return 0;
}
