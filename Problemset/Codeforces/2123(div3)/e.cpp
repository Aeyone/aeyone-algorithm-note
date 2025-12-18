#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 2);
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	vector<int> k(n + 2);
	int c = n;

	k[0] = 1;
	for(int i = 0; i < a.size(); i ++){
		if(a[0] > 0 || (i && a[i] - a[i - 1] > 1))
			break;
		int mxk = c, mnk = cnt[a[i]];
		k[mnk] ++, k[mxk + 1] --; 
		c --;
	}
	k[c + 1] --;

	vector<i64> res(n + 1);
	res[0] = k[0];
	for(int i = 1; i <= n; i ++)
		res[i] = res[i - 1] + k[i];

	for(int i = 0; i <= n; i ++)
		cout << res[i] << ' ';
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