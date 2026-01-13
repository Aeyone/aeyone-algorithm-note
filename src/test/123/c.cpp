#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<int> minp, p;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            p.push_back(i);
        }
        for (auto e : p) {
            if (1ll * i * e > n) {
                break;
            }
            minp[i * e] = e;
            if (e == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
	i64 k;
	cin >> k;
	auto divide = [&](int x)->int {
		int res = 0;
		for (int i = 1; i <= x / i; i ++) {
			if (x % i == 0) {
				res += (1 + (x / i != i));
			}
		}
		return res;
	};
	i64 cnt = 0;
	for (int i = 1; i <= 1e5; i ++) {
		cnt += divide(i);
	}
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// sieve(1e7);
	// cin >> _;
	while (_ --) {
		solve();
	}
}