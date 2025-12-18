	#include <bits/stdc++.h>
	using namespace std;

	using i64 = long long;

	void solve() {
		int n;
		cin >> n;
		vector<i64> a(n + 1), pre(n + 1, -1), suf(n + 2, -1);
		i64 sum = 0;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			sum += (i & 1 ? a[i] : -a[i]);
		}

		suf[n + 1] = (n & 1 ? n : n - 1);
		for(int i = n; i >= 1; i --){
			suf[i] = suf[i + 1];
			if((i & 1) && 2 * a[i] < 2 * a[suf[i]] - (suf[i] - i))
				suf[i] = i;
		}
		pre[0] = 1;
		for(int i = 1; i <= n; i ++){
			pre[i] = pre[i - 1];
			if((i & 1) && 2 * a[i] < 2 * a[pre[i]] - (i - pre[i]))
				pre[i] = i;
		}

		i64 mx = -1e9;
		if(n >= 3)
			mx = (n & 1 ? n : n - 1) - 1;
		for(int i = 2; i <= n; i += 2){
			i64 d1 = (a[i] - a[pre[i]]) - (a[pre[i]] - a[i]) + abs(i - pre[i]);
			i64 d2 = (a[i] - a[suf[i]]) - (a[suf[i]] - a[i]) + abs(suf[i] - i);
			mx = max(mx, max(d1, d2));
			// cout << "i = " << i << ": pre = " << pre[i] << " suf = " << suf[i] << " max = " << mx <<'\n';
		}
		// cout << '\n';
		if(mx > 0)
			sum += mx;
		cout << sum << '\n';

	}

	signed main() {
	//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int _ = 1;
		cin >> _;
		while (_ --)
			solve();
	}