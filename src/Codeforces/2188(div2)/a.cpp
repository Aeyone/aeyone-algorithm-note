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
	vector<int> a(n), b;
	iota(a.begin(), a.end(), 1);
	b = a;
	reverse(b.begin(), b.end());
	vector<int> res;
	for (int i = 1; i <= n; i ++) {
		if (i & 1) {
			res.push_back(b.back());
			b.pop_back();
		} else {
			res.push_back(a.back());
			a.pop_back();
		}
	}
	reverse(res.begin(), res.end());
	for (auto e : res) {
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