#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    vector<int> b;
    for(int i = 0; i < m; i++)
        b.push_back(max(a[i], a[i + n - m]));
    int sz = m - k;
    int ans = 0;
    deque<int> q;
    for(int i = 0, j = 0; i + sz - 1 < m; i++) {
        while(q.size() && q.front() < i)
            q.pop_front();
        while(j < i + sz) {
            while(q.size() && b[q.back()] >= b[j])
                q.pop_back();
            q.push_back(j++);
        }
        ans = max(ans, b[q.front()]);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
