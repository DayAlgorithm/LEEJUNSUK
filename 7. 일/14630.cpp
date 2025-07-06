#include <bits/stdc++.h>
using namespace std;

int cal(const string &a, const string &b) {
    int cost = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int da = a[i] - '0';
        int db = b[i] - '0';
        int diff = da - db;
        cost += diff * diff;
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int now, want;
    cin >> now >> want;
    now--;
    want--;

    vector<vector<pair<int,int>>> gp(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = cal(arr[i], arr[j]);
            gp[i].emplace_back(j, c);
            gp[j].emplace_back(i, c);
        }
    }

    const int INF = INT_MAX;
    
    vector<int> dist(n, INF);
    dist[now] = 0;


    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    
    pq.emplace(0, now);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]){
            continue;
        }

        if (u == want){
            break;
        }

        for (auto &e : gp[u]) {
            int v = e.first, w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }

    }

    int money = dist[want];
    cout << money << "\n";
    return 0;
}
