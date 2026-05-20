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
    int a[201][201] = {};

    Mat() {}

    Mat(int n, int m) {
        init(n, m);
    }

    void init(int n, int m) {
        this->n = n;
        this->m = m;
        memset(a, 0x3f, sizeof a);
    }

    void I() {
        for (int i = 0; i < n; i++) {
            a[i][i] = 0;
        }
    }

    Mat operator*(const Mat& T) const {
        Mat res(n, T.m);
        int r;
        for (int i = 0; i < n; i ++) {
            for (int k = 0; k < T.m; k ++) {
                r = a[i][k];
                for (int j = 0; j < m; j ++) {
                	res.a[i][j] = min(res.a[i][j], max(T.a[k][j], r));
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
	int n, m;
	cin >> n >> m;
	Mat M(n, n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		M.a[u][v] = 0;
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		M.a[u][v] = min(M.a[u][v], i);
	}

	int q, w;
	cin >> q >> w;
	M = M ^ w;

	while (q --) {
		int s, t;
		cin >> s >> t;
		s --, t --;
		cout << (M.a[s][t] > k ? -1 : M.a[s][t]) << '\n';
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