#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> g(4); 
int k; 

void rot(int i, int d) {
    if (d == 1) {
        char last = g[i][7];
        for (int j = 7; j > 0; j--) g[i][j] = g[i][j - 1];
        g[i][0] = last;
    } else {
        char first = g[i][0];
        for (int j = 0; j < 7; j++) g[i][j] = g[i][j + 1];
        g[i][7] = first;
    }
}

void go(int i, int d) {
    int dir[4] = {0};
    dir[i] = d;

    for (int j = i; j > 0; j--) {
        if (g[j][6] != g[j - 1][2]) dir[j - 1] = -dir[j];
        else break;
    }

    for (int j = i; j < 3; j++) {
        if (g[j][2] != g[j + 1][6]) dir[j + 1] = -dir[j];
        else break;
    }

    for (int j = 0; j < 4; j++) {
        if (dir[j] != 0) rot(j, dir[j]);
    }
}

int main() {
    for (int i = 0; i < 4; i++) cin >> g[i];

    cin >> k;
    while (k--) {
        int i, d;
        cin >> i >> d;
        go(i - 1, d);
    }

    int ans = 0;
    if (g[0][0] == '1') ans += 1;
    if (g[1][0] == '1') ans += 2;
    if (g[2][0] == '1') ans += 4;
    if (g[3][0] == '1') ans += 8;

    cout << ans << '\n';
    return 0;
}
