#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

struct Mat {
    int n, m;
    i64 a[60][60] = {};

    Mat() {}

    Mat(int n, int m) {
        init(n, m);
    }

    void init(int n, int m) {
        this->n = n;
        this->m = m;
    }

    void I() {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            a[i][i] = 1;
        }
    }

    Mat operator*(const Mat& T) const {
        Mat res(n, T.m);
        int r;
        for (int i = 0; i < n; i ++) {
            for (int k = 0; k < T.m; k ++) {
                r = a[i][k];
                for (int j = 0; j < m; j ++) {
                	res.a[i][j] += T.a[k][j] * r;
                	res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Mat operator^(i64 b) const {
        Mat res(n, m);
        res.I();
        Mat base = *this;
        while (b) {
            if (b & 1) {
                res = res * base;
            }
            base = base * base;
            b >>= 1;
        }
        return res;
    }
};

void solve() {
	int h, n;
	cin >> h >> n;
	vector g(n, vector<int>(n));
	vector dp(n, vector(n, vector<int>(1 << n)));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> g[i][j];
			if (g[i][j]) {
				dp[i][j][(1 << i) | (1 << j)] = 1;
				dp[j][i][(1 << i) | (1 << j)] = 1;
			}
		}
	}
	vector<vector<int>> mask(n + 1);
	for (int i = 0; i < 1 << n; i ++) {
		mask[__builtin_popcount(i)].push_back(i);
	}

	for (int len = 2; len <= n; len ++) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				for (auto e : mask[len]) {
					if (i == j || !(e >> i & 1) || !(e >> j & 1)) {
						continue;
					}
					for (int k = 0; k < n; k ++) {
						if (!g[j][k] || (e >> k & 1)) {
							continue;
						}
						dp[i][k][e | (1 << k)] = (dp[i][k][e | (1 << k)] + dp[i][j][e]) % MOD;
					}
				}
			}
		}
	}

	Mat res(1, n), b(n, n);
	res.a[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i == j) {
				b.a[i][j] = 1;
			}
			for (int k = 0; k < 1 << n; k ++) {
				b.a[i][j] = (b.a[i][j] + dp[i][j][k]) % MOD;
			}
		}
	}

	b = b ^ h;
	res = res * b;
	cout << res.a[0][0] << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}