#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;
unordered_map<int, int> memo;
using ll = long long;

ll power(ll x,ll y){
    return pow(x,y);
}


int find_num(int x) {
    if (x == 0) return 0;
    if (x == 1) return 3;
    if (memo.find(x) != memo.end()) return memo[x];
    int res = find_num(x / 2);
    res = (res % M * (power(10, x / 2)) % M + res % M) % M;
    if (x % 2 == 1) res = (res % M * 10 % M + 3 % M) % M;
    memo[x] = res;
    return res;
}

int main() {
    int tt;
    cin >> tt;

    for (int i = 0; i < tt; ++tt) {
        int x;
        cin >> x;
        int result = find_num(x) % M;
        cout << result << endl;
    }

    return 0;
}
