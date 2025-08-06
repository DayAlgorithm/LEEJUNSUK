#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int w, h;
vector<string> g;
pair<int, int> s, e;

struct Node {
    int y, x, d, c;
};

int bfs() {
    vector<vector<vector<int>>> vis(h, vector<vector<int>>(w, vector<int>(4, INF)));
    queue<Node> q;

    for (int d = 0; d < 4; ++d) {
        vis[s.second][s.first][d] = 0;
        q.push({s.second, s.first, d, 0});
    }

    while (!q.empty()) {
        auto [y, x, d, c] = q.front(); q.pop();

        for (int nd = 0; nd < 4; ++nd) {
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            int nc = c + (d != nd);

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (g[ny][nx] == '*') continue;
            if (vis[ny][nx][nd] <= nc) continue;

            vis[ny][nx][nd] = nc;
            q.push({ny, nx, nd, nc});
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; ++d)
        ans = min(ans, vis[e.second][e.first][d]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    g.resize(h);
    for (int i = 0; i < h; ++i) cin >> g[i];

    vector<pair<int, int>> p;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (g[i][j] == 'C')
                p.emplace_back(j, i);

    s = p[0];
    e = p[1];

    cout << bfs() << '\n';
}
