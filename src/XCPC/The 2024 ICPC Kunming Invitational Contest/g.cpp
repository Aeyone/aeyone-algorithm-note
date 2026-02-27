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
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	int cur = 0;
	for (int i = 0; i < n - 1; i ++) {
		if ((cur ^ a[i]) == 0) {
			swap(a[i], a[i + 1]);
		}
		cur ^= a[i];
	}
	cur ^= a.back();
	if (cur == 0) {
		cout << "impossible" << '\n';
		return;
	}
	for (auto e : a) {
		cout << e << ' ';
	}
	cout << '\n';
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