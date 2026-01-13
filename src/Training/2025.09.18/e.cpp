#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int self = a[0];
	sort(a.begin(), a.end(), greater<int>{});

	for(int i = 0; i < m; i ++){
		cin >> b[i];
		if(self >= b[i]){
			b[i] = 0;
			continue;
		}
		int l = 0, r = n - 1, ans = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[mid] >= b[i])
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		b[i] = ans + 1;
	}
	sort(b.begin(), b.end());
	vector<vector<int>> st(m, vector<int>(30));
	for(int i = 0; i < m; i ++)
		st[i][0] = b[i];

	for(int p = 1; m >> p > 0; p ++)
		for(int i = 0; i + (1 << p) <= m; i ++)
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		
	auto query = [&](int l, int r)->int{
		int d = log2(r - l + 1);
		return max(st[l][d], st[r - (1 << d) + 1][d]);
	};

	for(int i = 1; i <= m; i ++){
		i64 sum = 0;
		for(int j = 0; j + i - 1 < m; j += i){
			sum += (query(j, j + i - 1) + 1);
		}
		cout << sum << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}