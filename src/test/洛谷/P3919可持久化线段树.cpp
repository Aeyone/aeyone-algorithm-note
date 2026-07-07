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
    int test = 0;
#endif

const int MOD = 998244353;

template<class T>
struct SegmentTree {
	struct Info {
		T val = 0;
        int ls = 0, rs = 0;
	};

	int n, idx = 0;
	vector<Info> info;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		info.assign(n * 40, Info());
	}

	int build(int l, int r, const vector<T>& a) {
        int rt = ++ idx;
		if (l == r) {
			info[rt].val = a[l];
		} else {
            int mid = (l + r) / 2;
            info[rt].ls = build(l, mid, a);
            info[rt].rs = build(mid + 1, r, a);
        }
        return rt;
	}

	int modify(int p, int l, int r, int qi, T val) {
        int rt = ++ idx;
		if (l == r) {
            info[rt].val = val;
		} else {
            info[rt] = info[p];
            int mid = (l + r) / 2;
            if (qi <= mid) info[rt].ls = modify(info[rt].ls, l, mid, qi, val);
            if (qi > mid) info[rt].rs = modify(info[rt].rs, mid + 1, r, qi, val);
        }
        return rt;
	}

	Info query(int p, int l, int r, int qi) {
		if (l == r) {
			return info[p];
		}
		int mid = (l + r) / 2;
		if (qi <= mid) return query(info[p].ls, l, mid, qi);
		if (qi > mid) return query(info[p].rs, mid + 1, r, qi);
	}

	int build(const vector<T>& a) {
		return build(1, n, a);
	}

    // p为要修改的版本的头编号，返回更改后版本的头编号
	int modify(int p, int qi, T val) { 
		return modify(p, 1, n, qi, val);
	}

	Info query(int p, int qi) {
		return query(p, 1, n, qi);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), root(m + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    SegmentTree<int> st(std::max(n, m));
    root[0] = st.build(a);
    for (int i = 1; i <= m; i ++) {
        int v, op, idx;
        cin >> v >> op >> idx;
        if (op == 1) {
            int w;
            cin >> w;
            root[i] = st.modify(root[v], idx, w);
        } else {
            root[i] = root[v];
            cout << st.query(root[i], idx).val << '\n';
        }
    }
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