#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int l = -1, pre = 0;
	bool ok = false;
	for(int i = 0; i < n; i ++){
		pre += (a[i] <= k);
		ok |= (l != -1 && 2 * pre >= (i + 1) && pre >= 2);
		if(l == -1 && 2 * pre >= (i + 1))//中位数为<=k => 2 * cnt[<=k] >= len
			l = i;
	}
	int r = -1, suf = 0;
	for(int i = n - 1; i >= 0; i --){
		suf += (a[i] <= k);
		ok |= (r != -1 && 2 * suf >= (n - i) && suf >= 2);
		if(r == -1 && 2 * suf >= (n - i))
			r = i;
	}
	ok |= (l != -1 && r != -1 && l < r);
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}
