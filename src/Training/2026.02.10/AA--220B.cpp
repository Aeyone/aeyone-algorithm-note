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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}	
	vector<array<int, 3>> q(m);
	for (int i = 0; i < m; i ++) {
		auto &[l, r, id] = q[i];
		cin >> l >> r;
		id = i;
	}
	sort(q.begin(), q.end());

	Fenwick<int> fw(n + 10);
	vector<vector<int>> id(n + 1);
	vector<int> iid(n + 1), vis(n + 1);

	for (int i = 1; i <= n; i ++) {
		if (a[i] > n) {
			continue;
		}
		iid[i] = id[a[i]].size();
		id[a[i]].push_back(i);
	}

	auto update = [&](int i, int v)->void{ // 当前a[i]对a[i]-1和a[i]个a[i]之后的两个a[i]之间的区间造成1的贡献
		int to = iid[i] + a[i] - 1, siz = id[a[i]].size();
		if (to < siz) { 
			fw.rangeAdd(id[a[i]][to], to + 1 < siz ? id[a[i]][to + 1] - 1 : n, v);
		}
	};

	// 对于一个区间[l, r]，下标大于r的数字的贡献算不算对当前区间计算无影响
	for (int i = 1; i <= n; i ++) { // 将[1, n]区间所有第一次出现的数字贡献算好
		if (a[i] > n || vis[a[i]]) {
			continue;
		}
		update(i, 1);
		vis[a[i]] = true;
	}

	vector<int> ans(m);
	for (int i = 1, j = 0; i <= n && j < q.size(); i ++) { // 然后去移动左端点 删掉一些贡献 并同时更新贡献
		while (j < q.size() && i == q[j][0]) {
			auto &[l, r, idx] = q[j];
			ans[idx] = fw.query(r);
			j ++;
		}
		if (a[i] > n) { 
			continue;
		}
		update(i, -1); // 取消贡献
		vis[a[i]] = false;
		if (iid[i] + 1 < id[a[i]].size()) { // 如果还存在下一个数字
			update(id[a[i]][iid[i] + 1], 1);  // 更新贡献
			vis[a[i]] = true;
		}
	}
	for (auto e : ans) {
		cout << e << '\n';
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