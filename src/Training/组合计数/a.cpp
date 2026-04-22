#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

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
        a.assign(n, T{});
    }

    void add(int x, const T &v) { // 单点修改
        while(x <= n){
            a[x] += v, x += x & -x;
        }
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

    void rangeAdd(int l, int r, const T &v) { // 区间修改(差分优化)
        add(l, v), add(r + 1, -v);
    }
};

vector<i64> fac;

void init(int n) {
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	Fenwick<int> fw(n + 1);
	for (int i = 1; i <= n; i ++) {
		fw.add(i, 1);
	}
	i64 ans = 1;
	for (int i = 0; i < n; i ++) {
		fw.add(a[i], -1);
		int cnt = fw.query(a[i]);
		ans = (ans + fac[n - i - 1] * cnt % MOD) % MOD;
	}
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(1e6);
	while (_ --) {
		solve();
	}
}