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
			a[x] = max(a[x], v), x += x & -x;
		}
	}

	void modify(int l, int r, const T &v) { // 区间修改(差分优化)
		modify(l, v), modify(r + 1, -v);
	}
	
	T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
		T ans{};
		while(x > 0){
			ans = max(ans, a[x]), x -= x & -x;
		}
		return ans;
	}
	// 1-based
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	int N = n * m;
	vector<int> a(N + 1), id(N + 1), b(N + 1);
	for (int i = 1; i <= N; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i ++) {
		cin >> b[i];
	}
	auto tot = a;
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	auto find = [&](int x)-> int {
		return lower_bound(tot.begin(), tot.end(), x) - tot.begin();
	};

	for (int i = 1; i <= N; i ++) {
		id[find(a[i])] = i;
	}
	for (int i = 1; i <= N; i ++) {
		b[i] = id[find(b[i])];
	}

	Fenwick<int> fw(N + 1);
	int ans = 0;
	for (int i = 1; i <= N; i ++) {
		int x = fw.query(b[i] - 1) + 1;
		fw.modify(b[i], x);
		ans = max(ans, x);
	}
	cout << N - ans << '\n';
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