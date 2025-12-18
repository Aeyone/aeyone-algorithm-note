#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> cnt;
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	i64 A = 0, B = 0;
	vector<int> v;
	for(auto [num, c] : cnt){
		A += (i64)c * (num / 2), B += (i64)c * (num / 2);
		if(num & 1)
			v.push_back(c);
	}
	sort(v.begin(), v.end(), greater<int>{});
	for(int i = 0; i < v.size(); i ++){
		if(!(i & 1))
			A += v[i];
		else
			B += v[i];
	}
	cout << A << ' ' << B << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}