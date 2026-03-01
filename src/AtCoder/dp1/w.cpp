#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct Info {
    i64 sum = 0;
    i64 mn = 0;
};

struct Lazy {
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r) {
    Info res;
    res.sum = l.sum + r.sum;
    res.mn = min(l.mn, r.mn);
    return res;
}
 
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n);
    }

    void apply(int p, i64 val, int siz) {
        info[p].sum += val * siz;
        info[p].mn += val;
        lazy[p].add += val;
    }

    void down(int p, int sizL, int sizR) {
        if (lazy[p].add != 0) {
            apply(2 * p, lazy[p].add, sizL);
            apply(2 * p + 1, lazy[p].add, sizR);
            lazy[p].add = 0;
        }
    }

    void up(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r) {
        if (l == r) {
            info[p] = Info();
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, i64 val) {
        if (L > r || R < l) {
            return;
        }
        if (L <= l && r <= R) {
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R) {
        if(L > r || R < l) {
            return Info();
        }
        Info res;
        if(L <= l && r <= R) {
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, i64 val) {
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R) {
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	using T = array<int, 3>;
	vector<T> a(m);
	i64 tot = 0;
	for (auto &[r, l, w] : a) {
		cin >> l >> r >> w;
		l ++, r ++; // 要考虑从1开始的区间 也许可以在1位置放0 因此向右偏移一位
		tot += w;
	}
	sort(a.begin(), a.end());
	SegmentTree st(n + 2);
	// dp[i][j] 表示考虑所有右端点在1~i-1的区间内 上一个1的位置在j的最小负代价
	// j在此时的'1'位置，代表原数组1位置放0
	for (int i = 2, j = 0; i <= n + 2; i ++) {
		while (j < m && a[j][0] < i) {
			auto [r, l, w] = a[j];
			st.modify(1, l - 1, w);
			j ++;
		}
		st.modify(i, i, st.query(1, i - 1).mn);
	}
	cout << tot - st.query(1, n + 2).mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}