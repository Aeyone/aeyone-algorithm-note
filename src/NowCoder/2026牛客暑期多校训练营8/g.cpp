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
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> x1(a), x2(a + 1), y1(b), y2(b + 1);
	for (int i = 0; i < a; i ++) {
		x1[i] = x2[i] = 1;
	}
	x2.back() = 9;
	y1[0] = y2[0] = 9;
	y2.back() = 9;
	for (auto e : x1) cout << e;
	cout << ' ';
	for (auto e : y1) cout << e;
	cout << ' ';
	for (auto e : x2) cout << e;
	cout << ' ';
	for (auto e : y2) cout << e;
	cout << ' ';
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