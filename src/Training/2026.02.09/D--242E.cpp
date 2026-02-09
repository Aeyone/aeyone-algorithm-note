#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	线段树板子题，区间异或操作 + 区间求和
*	拆位，在线段树上维护每位上的0的数量和1的数量
*/

struct Info{
    int s0 = 0;
    int s1 = 0;
};

struct Lazy{
    bool tag = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.s1 = l.s1 + r.s1;
    res.s0 = l.s0 + r.s0;
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
    }

    void init(vector<int> &a){
        build(1, 1, n, a);
    }

    void apply(int p){
        swap(info[p].s0, info[p].s1);
        lazy[p].tag ^= 1;
    }

    void down(int p){
        if (lazy[p].tag){
            apply(2 * p);
            apply(2 * p + 1);
            lazy[p].tag = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r, vector<int> &a){
        if (l == r){
            info[p] = {!a[l], a[l]};
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, a);
            build(2 * p + 1, mid + 1, r, a);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){
            apply(p);
        }else{
            int mid = (l + r) / 2;
            down(p);
            modify(2 * p, l, mid, L, R);
            modify(2 * p + 1, mid + 1, r, L, R);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R){
        if(L > r || R < l){
            return Info();
        }
        Info res;
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            down(p);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R){
        modify(1, 1, n, L, R);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector st(21, SegmentTree(n));
	for (int i = 0; i < 21; i ++) {
		vector<int> bit(n + 1);
		for (int j = 1; j <= n; j ++) {
			bit[j] = (a[j] >> i & 1);
		}
		st[i].init(bit);
	}
	int m;
	cin >> m;
	while (m --) {
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1) {
			i64 ans = 0;
			for (int i = 0; i < 21; i ++) {
				ans += (1ll << i) * st[i].query(l, r).s1;
			}
			cout << ans << '\n';
		} else {
			int x;
			cin >> x;
			for (int i = 0; i < 21; i ++) {
				if (x >> i & 1) {
					st[i].modify(l, r);
				}
			}
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