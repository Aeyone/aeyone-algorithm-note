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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	int idx;
	cin >> idx;
	idx --;
	int suf = 0;
	for (int l = idx, r = idx; l < n; l = r) {
		while (r < n && a[r] == a[l]) {
			r ++;
		}
		suf ++;
	}
	int pre = 0;
	for (int l = idx, r = idx; l >= 0; l = r) {
		while (r >= 0 && a[r] == a[l]) {
			r --;
		}
		pre ++;
	}
	int ans = max(pre, suf);
	cout <<  ans - (ans & 1)  << '\n';
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