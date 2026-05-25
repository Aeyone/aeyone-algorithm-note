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
    	if (l > r) return 0;
        return query(r) - query(l - 1);
    }

};

void solve() {
	int n;
	cin >> n;
	i64 sum = 0;
	vector<int> a(n), pre(n);
	Fenwick<i64> fw1(n), fw2(n);
	for (int i = 0; i < n; i ++) { // 先计算出不减的代价
		cin >> a[i];
		fw1.modify(a[i], 1);
		fw2.modify(a[i], a[i]);
		pre[i] = fw1.query(a[i], n);
		sum += fw2.query(a[i], n) - 1ll * pre[i] * a[i];
	}
	i64 ans = 0;
	Fenwick<int> fw3(n);
	for (int i = n - 1; i >= 0; i --) { // d为移动次数 pre[i]为移动的长度len，即修改一次贡献为(d+1)*(len-1)-d*len
		i64 d = (n - i - 1) - fw3.query(a[i], n);
		fw3.modify(a[i], 1);
		ans = max(ans, (d + 1) * (pre[i] - 1) - d * pre[i]);
	}
	cout << sum + ans << '\n';
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