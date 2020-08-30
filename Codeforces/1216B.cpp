#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool cmp(pair<int, int> f, pair<int, int> s) {
	return f.first > s.first;
}
 
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n, a;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		v[i] = { a, i };
	}
	sort(v.begin(), v.end(), cmp);
	int res = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		res += i * v[i].first + 1;
		ans[i] = v[i].second + 1;
	}
	cout << res << endl;
	for (auto ai : ans)
		cout << ai << ' ';
	cout << endl;
	return 0;
}
