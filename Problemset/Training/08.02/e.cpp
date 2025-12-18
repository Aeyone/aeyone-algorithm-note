#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<i64> a(n + 1), s(n + 1), to(n + 1);
	map<i64, int> back;

	i64 suf = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i], s[i] = s[i - 1] + a[i], suf += s[i];
		to[i] = (i == 1 ? 1 : to[i - 1] + (n - i + 2));
		back[to[i]] = i;
	}

	int q; cin >> q;
	vector<pair<i64, i64>> seg(q);
	vector<vector<int>> st(n + 1);

	for(auto &[l1, r1] : seg){//l <= l1, r <= r1 -> L <= L1, R <= R1
		cin >> l1 >> r1;
		auto it = upper_bound(to.begin(), to.end(), l1);
		i64 l = *(-- it);
		it = upper_bound(to.begin(), to.end(), r1);
		i64 r = *(-- it);
		int L = back[l], R = back[r];
		if((l1 - l - 1) >= 0)
			st[L + (l1 - l - 1)].push_back(L);
		st[R + (r1 - r)].push_back(R);
	}

	vector<i64> cur(n + 1), b(n + 1), preSum(n + 1);
	map<pair<int, int>, i64> pre;

	for(int i = 1; i <= n; i ++){
		cur[i] = cur[i - 1] + s[i];//以1为开头i为底的总和
		for(auto e : st[i])
			pre[{e, i}] = cur[i] - cur[e - 1] - (i64)(i + 1 - e) * s[e - 1];
		b[i] = suf, suf -= a[i] * (n - i + 1);//以i开头n为底的总和
		preSum[i] = preSum[i - 1] + b[i];//b数组的前缀和
	}
	
	for(auto [l1, r1] : seg){
		auto it = upper_bound(to.begin(), to.end(), l1);
		i64 l = *(-- it);
		it = upper_bound(to.begin(), to.end(), r1);
		i64 r = *(-- it);
		int L = back[l], R = back[r];
		i64 ans = preSum[R - 1] - preSum[L - 1] + pre[{R, R + (r1 - r)}]; 
		if((l1 - l - 1) >= 0)
			ans -= pre[{L, L + (l1 - l - 1)}];
		cout << ans << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}