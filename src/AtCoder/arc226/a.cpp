#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
		res = a * res % p;
	}
	return res;
}

struct DSU {
	vector<int> f, siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool cmp(int x, int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x, int y) {//将y合并至x中
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	const int N = 2 * n + 2;
	vector<int> cnt(N);
	for (auto &[s, t] : a) {
		cin >> s >> t;
		cnt[s] ++;
		cnt[t + 1] --;
	}
	for (int i = 1; i < N; i ++) {
		cnt[i] += cnt[i - 1];
	}
	if (*max_element(cnt.begin(), cnt.end()) >= 3) {
		cout << 0 << '\n';
	} else {
		sort(a.begin(), a.end());
		vector<int> to(N), col(N, -1);
		iota(to.begin(), to.end(), 0);
		DSU dsu(n);
		for (int i = 0; i < n; i ++) {
			auto [l, r] = a[i];
			if (col[l] != -1) {
				dsu.merge(col[l], i);
			}
			for (int j = to[l]; j <= r; j ++) {
				to[j] = r + 1;
				col[j] = i;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i ++) {
			cnt += (dsu.find(i) == i);
		}
		cout << qmi(2, cnt, MOD) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}