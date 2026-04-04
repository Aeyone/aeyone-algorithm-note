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
	int n, p;
	cin >> n >> p;
	vector<i64> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; i ++) {
		inv[i] = (p - (p / i) * inv[p % i] % p);//O(N) (p为mod)
	}
	for (int i = 1; i <= n; i ++) {
		cout << inv[i]  << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}