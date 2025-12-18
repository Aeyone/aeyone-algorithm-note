#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for(int i = 0; i < n; i ++)
		cin >> p[i];

	map<string, int> mp;
	for(int i = 0; i < m; i ++){
		string s;
		cin >> s;
		mp[s] ++;	
	}

	vector<int> cnt;
	for(auto &[_, e] : mp)
		cnt.push_back(e);
	
	sort(p.begin(), p.end());
	sort(cnt.begin(),cnt.end(), [](int a, int b){return a > b; });

	int a = 0, b = 0, idx = 0;
	for(auto e : cnt)
		a += e * p[idx ++];

	idx = n - 1;
	for(auto e : cnt)
		b += e * p[idx --];
		// cout << e << "\n";

	cout << a << " " << b << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}