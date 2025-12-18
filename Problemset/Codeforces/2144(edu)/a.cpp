#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;
	int l = 0, r = 0;
	for(int i = 0; i < n - 1; i ++){
		for(int j = i + 1; j < n - 1; j ++){
			int s1 = 0, s2 = 0, s3 = 0;
			for(int k = 0; k < i; k ++)
				s1 += a[k];
			for(int k = i; k < j; k ++)
				s2 += a[k];
			for(int k = j; k < n; k ++)
				s3 += a[k];

			s1 %= 3, s2 %= 3, s3 %= 3;
			if(s1 != s2 && s1 != s3 && s2 != s3)
				l = i + 1, r = j + 1;
			if(s1 == s2 && s2 == s3)
				l = i + 1, r = j + 1;
		}
	}
	cout << l << ' ' << r << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}