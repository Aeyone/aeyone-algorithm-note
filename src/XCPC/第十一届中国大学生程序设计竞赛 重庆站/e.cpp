#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

template <typename T>
struct Fenwick {
	int n;
	vector<T> a;
	
	Fenwick(int n_ = 0) {
		init(n_);
	}
	
	void init(int n_) {
		n = n_;
		a.assign(n + 1, T{});
	}

	void modify(int x, const T &v) { // 单点修改
		while(x <= n){
			a[x] += v, x += x & -x;
		}
	}

	void modify(int l, int r, const T &v) { // 区间修改(差分优化)
		modify(l, v), modify(r + 1, -v);
	}
	
	T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
		T ans{};
		while(x > 0){
			ans += a[x], x -= x & -x;
		}
		return ans;
	}
	// 1-based
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}

	void fill () { //初始化为全1
		for (int x = 1; x <= n; x ++) {
			a[x] += x & (-x);
		}
	}

	int select (T k) { // 选择满足前缀和<=k的最大下标，要求所有值非负，且k从1开始
		int x = 0;
		T cur {};
		for (int i = __lg(n); ~i; i --) {
			x += (1 << i);
			if (x > n || cur + a[x] >= k) x -= (1 << i);
			else cur += a[x];
		}
		return x + 1;
	}
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i][1];
    for (int i = 0; i < n; i ++) cin >> a[i][0];
    sort(a.begin(), a.end());

    vector<int> id(n), u(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](const int &x, const int &y)-> bool {
        return a[x][1] < a[y][1];
    });
    for (int i = 0; i < n; i ++) {
        u[id[i]] = i;
    }

    Fenwick<int> f1(n), f2(n);
    f1.fill();
    for (int i = 0; i < n; i ++) {
        f2.modify(u[i] + 1, a[i][1]);
    }


    int ans = 0;
    for (int i = 0; i < n; i ++) {
        auto [R, w] = a[i];
        f1.modify(u[i] + 1, -1);
        f2.modify(u[i] + 1, -w);
        if (w <= R) {
            ans = max(ans, 1ll);
        }
        // for (int j = 1; j <= n - i - 1; j ++) {
        //     if (f2.query(f1.select(j)) + w <= R * (j + 1)) {
        //         ans = max(ans, j + 1);
        //     }
        // }
        int l = 1, r = n - i - 1;
        while (r - l >= 3) {
            int m1 = l + (r - l) / 3;
            int m2 = l + (r - l) * 2 / 3;
            int val1 = f2.query(f1.select(m1)) + w;
            int val2 = f2.query(f1.select(m2)) + w;
            if (val1 * (m2 + 1) < val2 * (m1 + 1)) {
                r = m2;
            } else if (val1 * (m2 + 1) > val2 * (m1 + 1)) {
                l = m1;
            } else {
                l = m1, r = m2;
            }
        }
        int min = f2.query(f1.select(l)) + w, idx = l;
        for (int j = l; j <= r; j ++) {
            int val = f2.query(f1.select(j)) + w;
            if (val * (idx + 1) < min * (j + 1)) {
                min = val;
                idx = j;
            }
        }

        l = idx, r = n - i - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f2.query(f1.select(mid)) <= R * (mid + 1) - w) {
                res = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, res + 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}