#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 100000007;

vector<int> minp, p, vis;
vector<i64> fac, inv;
vector<vector<i64>> nums(35);

i64 qmi(i64 a, i64 b, int p){
    i64 res = 1;
    for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
         res = a * res % p;
    }
    return res;
}

void init(int n) {
    fac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}
 
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
    vis.assign(n + 1, 0);
    for (int i = 2; i <= n; i ++) {
    	if (vis[i]) {
    		continue;
    	}
    	for (i64 x = i; x <= n; x *= i) {
    		vis[x] = true;
    	}
		nums[1].push_back(i);
    }
    int m = nums[1].size();
    for (int i = 2; i <= 34; i ++) {
    	nums[i].assign(m, 0);
    	for (int j = 0; j < m; j ++) {
    		i64 e = nums[i - 1][j] * nums[1][j];
    		nums[i][j] = (e <= 1e10 ? e : 1e12);
    	}
    }
}

int C(int N, int M) {
    if (M > N || M < 0) {
        return 0;
    }
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int get(i64 x) {
	int tot = 0;
	for (int i = 2; i <= 34; i ++) {
		int cnt = upper_bound(nums[i].begin(), nums[i].end(), x) - nums[i].begin();
		tot += cnt;
		if (!cnt) {
			break;
		}
		// cerr << "i = " << i << ' ';
		// cerr << "select: " <<  nums[i][cnt - 1] << ' ';
		// cerr << "cnt = " << cnt << '\n';
	}
	return tot;
}

void solve() {
	i64 l, r;
	cin >> l >> r;
	int n = get(r) - get(l - 1);
	// cerr << "n = " << n << '\n';
	if (n == 0) {
		cout << 0 << '\n';
	} else {
		cout << (C(2 * n, n) - C(2 * n, n - 1) + MOD) % MOD << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	sieve(1e5);
	init(3e5);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}