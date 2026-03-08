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
	int x;
	cin >> x;
	int cnt = 0;
	for (int i = 1; i <= 100; i ++) {
		string s = to_string(x + i);
		int sum = 0;
		for (auto e : s) {
			sum += (e - '0');
		}
		cnt += (sum == i);
	}
	cout << cnt << '\n';
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