#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2000000;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> isPrime(N + 1, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    sieve();

    ll f = 0, s = 0;

    for (ll i = 4; i <= n / 2; i++) {
        ll j = n - i;
        if (!isPrime[i] && !isPrime[j]) {
            f = i;
            s = j;
            break;
        }
    }

    cout << f << " " << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tt = 1;
    // cin>>tt;

    while (tt--) {
        solve();
    }
}
