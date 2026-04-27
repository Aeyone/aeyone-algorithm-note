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

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p = MOD){
    i64 res = 1;
    for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
        res = a * res % p;
    }
    return res;
}

void init(int n) {
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

const int N = 2e5;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1), cnt(N + 1);
	Fenwick<int> fw(N);
	i64 rk = 1, sfac = 1, sum = 0;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		fw.modify(i, 1);
		cnt[a[i]] ++;
		sfac = sfac * cnt[a[i]] % MOD;
	}

	// for (int i = 1; i <= N; i ++) if (cnt[i] > 0) {
	// 	sum += cnt[i];
	// }

	for (int i = 1; i <= n; i ++) {
		int tot = fw.query(a[i] - 1);
		rk = (rk + tot * fac[n - i] % MOD * qmi(sfac, MOD - 2) % MOD) % MOD;
		sfac = sfac * qmi(cnt[a[i]], MOD - 2) % MOD;
		cnt[a[i]] --;
		// if (!cnt[a[i]]) {
			fw.modify(a[i], -1);
		// }
	}
	cout << rk << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(N);
	int _ = 1;
	while (_ --) {
		solve();
	}
}