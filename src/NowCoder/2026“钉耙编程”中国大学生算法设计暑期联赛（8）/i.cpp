#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n);
	set<int> st;
	for (int i = 0; i < 2 * n; i ++) {
		st.insert(i + 1);
		cin >> a[i];
	}
	for (int i = 0; i < 2 * n; i += 2) {
		if (!a[i] || !a[i ^ 1]) continue;
		st.erase(a[i]);
		st.erase(a[i ^ 1]);
	}
	if (st.size() == 0) {
		cout << 1 << '\n';
		return;
	}
	vector<int> v;
	for (auto e : st) v.push_back(e);
	int mid = v[v.size() / 2 - 1];

	int m1 = v.size() / 2, m2 = v.size() / 2;
	i64 ans = 1;
	for (int i = 0; i < 2 * n; i += 2) {
		if (a[i] && a[i ^ 1]) continue;
		if (!a[i] && !a[i ^ 1]) {
			ans = (ans * 2) % MOD;
			continue;
		}
		int x;
		if (a[i]) x = a[i];
		if (a[i ^ 1]) x = a[i ^ 1];
		if (x <= mid) m1 --;
		else m2 --;
	}
	// cout << m1 << ' ' << m2 << '\n';

	vector<i64> fac(2 * n + 1, 1);
	for (int i = 2; i <= 2 * n; i ++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	cout << ans * fac[m1] % MOD * fac[m2] % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}