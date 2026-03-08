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
	vector<vector<int>> idx(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] < n) {
			idx[a[i]].push_back(i);
		}
	}
	int cnt = 0;
	for (int i = 1; i < n; i ++) {
		
		for (int d = i; d < n; d += i) {
			int num = d / i;
			for (auto u : idx[i]) {

			}
		}
	}
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