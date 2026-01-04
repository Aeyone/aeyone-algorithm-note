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
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});//初始化大小为n + 1
    }

    void add(int x, const T &v) {//单点修改
        while(x <= n)
            a[x] += v, x += x & -x;
    }
    
    T sum(int x) {//查询1~x的和
        T ans{};
        while(x > 0)
            ans += a[x], x -= x & -x;
        return ans;
    }
    //1-based
    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(n);
	vector<int> la(m, -1), cnt(m);
	vector<i64> ans(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0];
		cnt[a[i][0]] ++;
		a[i][1] = i + 1;
	}
	for (int i = 0; i < n; i ++) {
		ans[a[i][0]] += 1ll * cnt[a[i][0]] * (i - la[a[i][0]] - 1);
		cnt[a[i][0]] -= 2;
		la[a[i][0]] = i;
	}
	for (int i = 0; i < m; i ++) {
		if (la[i] == -1) {
			continue;
		}
		ans[i] += (1ll * cnt[i] * (n - la[i] - 1));
	}
	sort(a.begin(), a.end(), greater<array<int, 2>>{});
	Fenwick<int> fw(n);
	i64 tot = 0;
	for (int i = 0; i < n; i ++) {
		tot += fw.sum(a[i][1] - 1);
		fw.add(a[i][1], 1);
	}
	cout << tot << '\n';
	for (int i = 1; i < m; i ++) {
		tot += ans[m - i];
		cout << tot << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}