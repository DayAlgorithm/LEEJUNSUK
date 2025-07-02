#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long, long long>> villages(n);
    for(int i = 0; i < n; i++){
        cin >> villages[i].first >> villages[i].second; 
    }
    sort(villages.begin(), villages.end());

    long long total = 0;
    for(auto &v : villages) total += v.second;
    long long half = (total + 1) / 2;

    long long a = 0;
    for(auto &v : villages){
        a += v.second;
        if(a >= half){
            cout << v.first << "\n";
            break;
        }
    }

    return 0;
}
