#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int mxi = 0, mni = 2e9, mxj = 0, mnj = 2e9;
	for(int i = 0; i < n; i ++){
		int a, b;
		cin >> a >> b;
		mxi = max(mxi, a);
		mni = min(mni, a);
		mxj = max(mxj, b);
		mnj = min(mnj, b);
	}
	cout << max((mxi - mni + 1) / 2, (mxj - mnj + 1) / 2) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}