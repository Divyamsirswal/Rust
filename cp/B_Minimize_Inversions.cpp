#include<bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> mi(int n, vector<int>& a, vector<int>& b) {

    vector<pair<int, int>> si;
    for (int i = 0; i < n; ++i) {
        si.push_back({a[i], b[i]});
    }

    sort(si.begin(), si.end());

    vector<int> a_sorted, b_sorted;
    for (const auto& pair : si) {
        a_sorted.push_back(pair.first);
        b_sorted.push_back(pair.second);
    }

    return {a_sorted, b_sorted};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);


        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        auto result = mi(n, a, b);

        for (int i = 0; i < n; ++i) {
            cout << result.first[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; ++i) {
            cout << result.second[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
