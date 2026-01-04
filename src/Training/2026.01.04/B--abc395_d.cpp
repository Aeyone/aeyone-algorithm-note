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
	int n, q;
	cin >> n >> q;
	vector<int> idx(n), arr(n), u(n);
	iota(idx.begin(), idx.end(), 0);
	iota(u.begin(), u.end(), 0);
	iota(arr.begin(), arr.end(), 0);

	while (q --) {
		int sign;
		cin >> sign;
		if (sign == 1) {
			int a, b;
			cin >> a >> b;
			a --, b --;
			arr[a] = idx[b];
		}
		if (sign == 2) {
			int a, b;
			cin >> a >> b;
			a --, b --;
			swap(u[idx[a]], u[idx[b]]);
			swap(idx[a], idx[b]);
		}
		if (sign == 3) {
			int x;
			cin >> x;
			x --;
			cout << u[arr[x]] + 1 << '\n';
		}

	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}