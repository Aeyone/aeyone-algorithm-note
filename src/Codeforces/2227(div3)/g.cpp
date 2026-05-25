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
};

int get(vector<i64>& tot, i64 x) {
	return 1 + ranges::lower_bound(tot, x) - tot.begin();
}

i64 run(vector<int> a) {
	int n = a.size();

	vector<i64> tot = {0, 1};
	i64 cur = 0;
	for (int i = 0; i < n; i += 2) {
		i64 d = (!i ? 0 : a[i] - a[i - 1]);
		cur -= d;
		tot.push_back(cur + 1);
		tot.push_back(cur + a[i]);
	}

	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());
	int m = tot.size();

	Fenwick<int> fw(m);

	cur = 0;
	i64 res = 0;
	for (int i = 0; i < n; i += 2) {
		i64 d = (!i ? 0 : a[i] - a[i - 1]);
		cur -= d;
		fw.modify(get(tot, cur + a[i]), 1);
		res += fw.query(get(tot, cur + 1), m);
	}
	return res;
}
/*
	n=3时: 需要满足 1-2+3>0
	n=5时: 1-2+3-4+5>0时，一定可以得到1-2+3>0或者3-4+5>0
	所以归纳一下，满足条件的数组即为奇数位之和减去偶数位之和大于0的数组
*/

void solve() { 
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> b(a.begin() + 1, a.end());

	cout << run(a) + run(b) << '\n';
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