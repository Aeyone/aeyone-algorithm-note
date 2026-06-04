#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

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
	i64 n;
	cin >> n;
	Mat m(3), res(3);
	m.a = {{}}
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