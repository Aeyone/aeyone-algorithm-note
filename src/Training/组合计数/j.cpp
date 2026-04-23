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
	int n, k;
	cin >> n >> k;
	vector<int> prm;
	int x = n;
	while (x > 1) {
		int p = minp[x];
		while (x % p == 0) {
			x /= p;
		}
		prm.push_back(p);
	}
	int m = prm.size();

	auto check = [&](i64 x)-> bool {
		i64 cnt = 0;
		for (int mask = 1; mask < 1 << m; mask ++) {
			i64 num = x;
			for (int i = 0; i < m; i ++) if (mask >> i & 1) {
				num /= prm[i];
			}
			cnt += num * (__builtin_popcount(mask) & 1 ? 1 : -1);
		}
		// cerr << "x = " << x << ' ';
		// cerr << "cnt = " << cnt << '\n';
		return (x - cnt >= k);
	};

	i64 l = 1, r = 1e16, ans = 0;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	sieve(1e6);
	int _ = 1;
	while (_ --) {
		solve();
	}
}