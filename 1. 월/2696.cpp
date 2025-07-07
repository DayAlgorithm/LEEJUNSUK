#include <bits/stdc++.h>
using namespace std;

void center(int m) {
    priority_queue<int> maxq; 
    priority_queue<int, vector<int>, greater<int>> minq; 

    cout << (m + 1) / 2 << '\n';

    int che = 0; 

    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;

        if (maxq.empty() || s <= maxq.top()) {
            maxq.push(s);
        } 
        else {
            minq.push(s);
        }


        if (maxq.size() > minq.size() + 1) {
            minq.push(maxq.top());
            maxq.pop();
        } 
        else if (minq.size() > maxq.size()) {
            maxq.push(minq.top());
            minq.pop();
        }


        if (i % 2 == 1) {
            cout << maxq.top() << ' ';
            che++;


            if (che == 10) {
                cout << '\n';
                che = 0;
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, m;
    cin >> t;

    while (t--) {
        cin >> m;
        center(m);
    }


    
    return 0;
}
