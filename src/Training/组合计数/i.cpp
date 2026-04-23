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
vector<i64> fac = {1};
 
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
    for (int i = 1; i <= n; i++) {
    	if (fac[i - 1] * i > INFLL) {
    		break;
    	}
        fac.push_back(fac[i - 1] * i);
    }
}

void solve() {
	int n;
	while (cin >> n) {
		int x = n, sum = 0;
		vector<int> v;
		while (x > 1) {
			int p = minp[x], cnt = 0;
			while (x % p == 0) {
				x /= p;
				cnt ++;
			}
			sum += cnt;
			v.push_back(cnt);
		}
		i64 res = fac[sum];
		for (auto e : v) {
			res /= fac[e];
		}
		cout << sum << ' ' << res << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	sieve(2e6);
	int _ = 1;
	while (_ --) {
		solve();
	}
}