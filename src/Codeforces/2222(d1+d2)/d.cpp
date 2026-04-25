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

int get(vector<i64> &tot, i64 x) {
	return 1 + ranges::lower_bound(tot, x) - tot.begin();
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<i64> pre(n + 1), tot;
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}
	tot = pre;
	ranges::sort(tot);
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	int m = tot.size();
	Fenwick<int> fw(m), vis(n);
	vis.fill();

	vector<int> ans(n + 1);
	for (int i = 1; i < n; i ++) {
		fw.modify(get(tot, pre[i]), 1);
	}
	
	for (int i = 1; i <= n; i ++) {
		int cnt = fw.query(get(tot, pre[i - 1]), m);
		// cerr << "cnt = " << cnt << '\n';
		ans[i] = vis.select(cnt + 1);
		vis.modify(ans[i], -1);
		fw.modify(get(tot, pre[i]), -1);
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

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