#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<class T>
struct SegmentTree {
    struct Info {
        T g = 0;
        friend Info operator+(const Info& l, const Info& r) {
            return {
                __gcd(l.g, r.g)
            };
        }
    };

    int n;
    vector<Info> info;

    SegmentTree(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        info.assign(n << 2, Info());
    }

    void pushup(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void build(int p, int l, int r, const vector<T>& a) {
        if (l == r) {
            info[p] = {a[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid + 1, r, a);
        pushup(p);
    }

    void modify(int p, int l, int r, int q, T val) {
        if (q <= l && r <= q) {
            info[p].g = val;
            return;
        }
        int mid = (l + r) / 2;
        if (q <= mid) modify(2 * p, l, mid, q, val);
        if (q > mid) modify(2 * p + 1, mid + 1, r, q, val);
        pushup(p);
    }

    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return info[p];
        }
        Info res {};
        int mid = (l + r) / 2;
        if (ql <= mid) res = res + query(2 * p, l, mid, ql, qr);
        if (qr > mid) res = res + query(2 * p + 1, mid + 1, r, ql, qr);
        return res;
    }

    void build(const vector<T>& a) { // 1-based
        build(1, 1, n, a);
    }

    void modify(int q, T val) {
        modify(1, 1, n, q, val);
    }

    Info query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	SegmentTree<int> st(n);
	st.build(a);
	int q;
	cin >> q;
	while (q --) {
		int c;
		cin >> c;
		if (c == 1) {
			int L, R, x;
			cin >> L >> R >> x;
			int l = L, r = R, ans = -1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if(st.query(L, mid).g % x != 0) {
					ans = mid, r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			if (ans == -1 || st.query(ans + 1, R).g % x == 0) {
				cout << "YES" << '\n';
			} else {
				cout << "NO" << '\n';
			}
		} else {
			int idx, x;
			cin >> idx >> x;
			st.modify(idx, x);
		}
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