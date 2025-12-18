#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 1e6 + 10;

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
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<i64> a(n), b(n);
	map<i64, int> mp;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] = 1;

	b = a;
	vector<int> p(q), v(q);
	for(int i = 0; i < q; i ++){
		cin >> p[i] >> v[i];
		p[i] --;
		b[p[i]] += v[i];
		mp[b[p[i]]] = 1;
	}
	Fenwick<i64> tree(mp.size());
	int idx = 1;
	for(auto &[_, e] : mp)
		e = idx ++;
		// cout << _ << ' ';

	for(int i = 0; i < n; i ++)
		tree.add(mp[a[i]], 1);

	for(int i = 0; i < q; i ++){
		tree.add(mp[a[p[i]]], -1);
		a[p[i]] += v[i];
		tree.add(mp[a[p[i]]], 1);

		// cout << mp[a[p[i]]] << '\n';
		int l = 1, r = mp.size(), ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(tree.sum(mid) <= (n + 1) / 2)
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		cout << tree.sum(ans) << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}