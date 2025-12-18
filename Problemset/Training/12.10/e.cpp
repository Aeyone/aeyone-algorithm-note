#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<int>> st(n, vector<int>(20));
	for(int i = 0; i < n; i ++) {
		st[i][0] = a[i];
	}
	for(int p = 1; n >> p > 0; p ++) {
		for(int i = 0; i + (1 << p) <= n; i ++) {
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->int{
		int d = __lg(r - l + 1);
		return max(st[l][d], st[r - (1 << d) + 1][d]);
	};

	vector<i64> ans(n + 3), d1(n + 3), d2(n + 3), d3(n + 3);
	for(int i = 0; i < n; i ++) {
		int ans1 = i, ans2 = i;
		int l = 0, r = i - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(query(mid, i - 1) < a[i]){
				ans1 = mid, r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		l = i, r = n - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(query(i, mid) <= a[i]){
				ans2 = mid, l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		int mn = min(i - ans1 + 1, ans2 - i + 1);
		int mx = max(i - ans1 + 1, ans2 - i + 1);
		int len = ans2 - ans1 + 1;
		d1[mn] += 1ll * mn * a[i];
		d1[mx + 1] -= 1ll * mn * a[i];

		d2[1] += a[i];
		d2[mn] -= 1ll * a[i] * mn;
		d2[mn + 1] += 1ll * a[i] * (mn - 1);

		d3[len] += a[i];
		d3[mx] -= 1ll * a[i] * (len - mx + 1);
		d3[mx - 1] += 1ll * a[i] * (len - mx);
	}
	for(int i = n - 1; i >= 0; i --) {
		d3[i] += d3[i + 1];
	}
	for(int i = n - 1; i >= 0; i --) {
		d3[i] += d3[i + 1];
	}
	for(int i = 1; i <= n; i ++) {
		d2[i] += d2[i - 1];
	}
	for(int i = 1; i <= n; i ++) {
		d2[i] += d2[i - 1];
		d1[i] += d1[i - 1];
	}
	for(int i = 1; i <= n; i ++) {
		cout << d1[i] + d2[i] + d3[i] << '\n';
	}
}	

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}