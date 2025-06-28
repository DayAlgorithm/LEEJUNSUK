#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;
    while (B.size() > A.size()) {
        if (B.back() == 'A') {
            B.pop_back();
        } 
        else {
            B.pop_back();
            reverse(B.begin(), B.end());
        }
    }
    cout << (B == A ? 1 : 0) << '\n';
    return 0;
}
