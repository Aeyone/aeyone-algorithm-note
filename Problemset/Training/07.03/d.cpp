#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), res;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	sort(a.begin(), a.end());
	if(a.back() - a.front() == 0){
		cout << "No" << '\n';
		return;
	}
	i64 sum = 0;
	int l = 0, r = n - 1;
	while(res.size() < n){
		res.push_back(a[l]);
		sum += a[l ++];

		while(res.size() < n && sum < 0){
			res.push_back(a[r]);
			sum += a[r --];
		}
	}
	cout << "Yes" << '\n';
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}