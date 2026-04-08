#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int a[1000][1000];

int query (int i, int j, int k) {
	return (a[i][j] <= k);
    // cout << "? " << i << " " << j << " " << k << endl;
    // int op;
    // cin >> op;
    // return op;
}

void answer (int x) {
    cout << "! " << x << endl;
}

#define U dfs (lx, midx, ly, ry, q)
#define D dfs (midx + 1, rx, ly, ry, q)
#define L dfs (lx, rx, ly, midy, q)
#define R dfs (lx, rx, midy + 1, ry, q)
#define RU dfs (lx, midx, midy + 1, ry, q)
#define RD dfs(midx + 1, rx, midy + 1, ry, q)


int dfs (int lx, int rx, int ly, int ry, int q) {
	// cerr << "L : " << lx << ' ' << ly << '\n';
	// cerr << "R : " << rx << ' ' << ry << '\n';
	if (lx > rx || ly > ry) {
		return 0;
	}
	if (lx == rx && ly == ry) {
		// cerr << "add " << !query(lx, ly, q) << '\n';
		return !query(lx, ly, q);
	}
    int midx = (lx + rx) / 2, midy = (ly + ry) / 2;
	if (lx == rx) {
		if (!query(lx, midy + 1, q)) {
			// cerr << "add " << (ry - midy) << '\n';
			return (ry - midy) + L;
		} else {
			return dfs(lx, rx, midy + 1, ry, q);
		}
	}
	if (ly == ry) {
		if (!query(midx + 1, ly, q)) {
			// cerr << "add " << (rx - midx)<< '\n';
			return (rx - midx) + U;
		} else {
			return dfs(midx + 1, rx, ly, ry, q);
		}
	}
	if (!query(lx, midy + 1, q)) {
		// cerr << "add R " << (ry - midy) * (rx - lx + 1)<< '\n';
		return (ry - midy) * (rx - lx + 1) + L; // 左半
	}
	if (!query(midx + 1, ly, q)) {
		// cerr << "add D " << (rx - midx) * (ry - ly + 1) << '\n';
		return (rx - midx) * (ry - ly + 1) + U; // 上半
	}
	if (!query(midx + 1, midy + 1, q)) {  // 左半 + 右上
		// cerr << "add RD " << (rx - midx) * (ry - midy) << '\n';
		return (rx - midx) * (ry - midy) + L + RU;
	}
	return D + RU;
}
/*
1 2
3 4
*/

static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define rand(l, r) (uniform_int_distribution<int>((l),(r))(rng))

void solve () {
    int n, k;
    // cin >> n >> k;
    n = 10, k =2;
    int l = 1, r = n * n, ans = -1;

    vector<int> cnt(n * n + 1), suf(n * n + 1);
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= n; j ++) {
    		a[i][j] = rand((max({1, a[i - 1][j], a[i][j - 1]})), i * i);
    		// cin >> a[i][j];
    		cnt[a[i][j]] ++;
    		cout << a[i][j] << ' ';
    	}
    	cout << '\n';
    }
    	cout << '\n';
    int cur = 0;
    for (int i = n * n; i >= 1; i --) {
    	suf[i] = cur;
    	cur += cnt[i];
    }
    cout << "real = ";
    for (int i = 1; i <= n * n; i ++) {
    	cout << suf[i] << ' ';
    }
    cout << '\n';
    // cout << dfs (1, n, 1, n, 99) << '\n';

    vector<int> v;
    cout << "check = ";
    for (int i = 1; i <= n * n; i ++) {
    	int x = dfs (1, n, 1, n, i);
    	cout << x << ' ';
    	if (x != suf[i]) {
    		v.push_back(i);
    	}
    }
    cout << '\n';
    if (v.size() != 0) {
    	int x;
    	cin >> x;
    }

    for (auto e : v) {
    	cout << e << ' ';
    }
    cout << '\n';

    // while (l <= r) {
    // 	int mid = (l + r) / 2;
    //     if (dfs (1, n, 1, n, mid) >= k) {
    //         ans = mid + 1;
    //         l = mid + 1;
    //     } else {
    //         r = mid - 1;
    //     }
    // }
    // answer (ans);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (1) {
		solve();
	}
}