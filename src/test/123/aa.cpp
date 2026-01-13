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
	if (n % 4 == 0) {
		cout << 0 << '\n';
		return;
	}
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	while (a.size() >= 4) {
		for (auto e : a) {
			cout << e << ' ';
		}
		cout << '\n';
		vector<int> v;
		for (int i = 0; i < a.size(); i ++) {
			if ((i + 1) % 5 == 0) {
				v.push_back(a[i]);
			}
		}
		int r = a.size() % 5;
		if (r < 4) {
			for (int i = r; i >= 1; i --) {
				v.push_back(a[a.size() - i]);
			}
		}
		a = v;
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
	// cin >> _;
	while (_ --) {
		solve();
	}
}