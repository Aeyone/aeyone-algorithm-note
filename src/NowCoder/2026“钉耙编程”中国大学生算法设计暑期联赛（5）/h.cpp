#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

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
	
	T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
		T ans{};
		while(x > 0){
			ans = max(ans, a[x]), x -= x & -x;
		}
		return ans;
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> tot;
    vector<array<int, 2>> rg(n);
    vector<array<int, 3>> que(q);
    for (auto &[l, r] : rg) {
        cin >> l >> r;
        tot.push_back(l);
        tot.push_back(r);
    }
    for (int i = 0; i < q; i ++) {
        auto &[l, r, id] = que[i];
        cin >> l >> r;
        id = i;
        tot.push_back(l);
        tot.push_back(r);
    }
    sort(rg.begin(), rg.end());
    sort(que.begin(), que.end(), greater<array<int, 3>>{});
    
    sort(tot.begin(), tot.end());
    tot.erase(unique(tot.begin(), tot.end()), tot.end());

    auto find = [&](int x)-> int {
        return 1 + lower_bound(tot.begin(), tot.end(), x) - tot.begin();
    };
    
    Fenwick<int> st(tot.size());

    vector<int> ans(q);
    for (auto [L, R, id] : que) {
        while (rg.size() && rg.back()[0] >= L) {
            auto [l, r] = rg.back();
            st.modify(find(r), r - l + 1);
            rg.pop_back();
        }
        ans[id] = st.query(find(R));
    }
    
    for (auto e : ans) cout << e << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}