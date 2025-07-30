#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<string> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int l = s.length();
    vector<bool> dp(l + 1, false);
    dp[l] = true; 

    for (int i = l - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int wl = w[j].length();
            if (i + wl <= l && s.substr(i, wl) == w[j] && dp[i + wl]) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << dp[0] << '\n';
    return 0;
}