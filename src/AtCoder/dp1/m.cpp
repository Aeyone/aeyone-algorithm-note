#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) { // 单点修改
    	x ++;
        while(x <= n){
            a[x] = (a[x] + v) % MOD, x += x & -x;
        }
    }
    
    T query(int x) {// 查询1~x的和 / 单点查询(差分优化)
    	x ++;
        T ans{};
        while(x > 0){
            ans = (ans + a[x]) % MOD, x -= x & -x;
        }
        return ans % MOD;
    }
    // 0-based
    T query(int l, int r) {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }

    void rangeAdd(int l, int r, const T &v) { // 区间修改(差分优化)
    	add(l, v), add(r + 1, (MOD - v) % MOD);
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector dp(n + 1, Fenwick<i64>(m + 10));
	dp[0].rangeAdd(m, m, 1);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= m; j ++) {
			i64 cur = dp[i].query(j);
			dp[i + 1].rangeAdd(max(0, j - a[i + 1]), j, cur);
		}
	}
	cout << dp[n].query(0) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}