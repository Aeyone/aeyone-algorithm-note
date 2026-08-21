#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<int> minp, p, phi;
 
void sieve(int n) {
	minp.assign(n + 1, 0);
	phi.assign(n + 1, 0);
	p.clear();
	for (int i = 2; i <= n; i++) {
		if (minp[i] == 0) {
			minp[i] = i;
			phi[i] = i - 1;
			p.push_back(i);
		}
		for (auto e : p) {
			if (1ll * i * e > n) {
				break;
			}
			minp[i * e] = e;
			if (e == minp[i]) {
				phi[i * e] = phi[i] * e;
				break;
			} else {
				phi[i * e] = phi[i] * (e - 1);
			}
		}
	}
}

void solve() {
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	sieve(1e5);
	cout << p.size() << '\n';
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}