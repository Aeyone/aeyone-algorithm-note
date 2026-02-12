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
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int cur = n, idx = 0;
	while (idx < n && a[idx] == cur) {
		idx ++, cur --;
	}
	int to = n - 1;
	for (int i = 0; i < n; i ++) {
		if (a[i] == cur) {
			to = i;
		}
	}
	reverse(a.begin() + idx, a.begin() + to + 1);
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