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

void solve() {
	int n; 
	i64 t;
	cin >> n >> t;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<i64> pre(n + 1), alls;
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}
	alls = pre;
	for (auto e : pre) {
		alls.push_back(e - t);
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	auto getIdx = [&](i64 num)->int{
		return 1 + lower_bound(alls.begin(), alls.end(), num) - alls.begin();
	};

	Fenwick<int> fw(alls.size() + 10);
	fw.rangeAdd(1, getIdx(0), 1);
	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += fw.query(getIdx(pre[i] - t) + 1);
		fw.rangeAdd(1, getIdx(pre[i]), 1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}