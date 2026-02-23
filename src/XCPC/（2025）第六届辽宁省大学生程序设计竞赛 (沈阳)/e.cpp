#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct Info{
    array<int, 10> cnt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

struct Lazy{
	int add = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    for (int i = 0; i < 10; i ++) {
    	res.cnt[i] = l.cnt[i] + r.cnt[i];
    }
    return res;
}
 
struct SegmentTree{
    int n, m;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n, int _m, vector<int> &a) {
        init(_n, _m, a);
    }

    void init(int _n, int _m, vector<int> &a){
        n = _n;
        m = _m;

        info.assign(n << 2, Info({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
        lazy.assign(n << 2, Lazy());
        build(1, 1, n, a);
    }

    void apply(int p, int val, int siz){
        array<int, 10> res = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < m; i ++) {
        	res[(i + (val % m)) % m] += info[p].cnt[i];
        }
        info[p].cnt = res;
        lazy[p].add = (lazy[p].add + val) % m;
    }

    void down(int p, int sizL, int sizR){
        if (lazy[p].add != 0){
            apply(2 * p, lazy[p].add, sizL);
            apply(2 * p + 1, lazy[p].add, sizR);
            lazy[p].add = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r, vector<int> &a){
        if (l == r){
            info[p].cnt[a[l - 1] % m] = 1;
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, a);
            build(2 * p + 1, mid + 1, r, a);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, int val){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
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
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, int val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), siz(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		int cur = 0;
		string s = to_string(a[i]);
		for (auto e : s) {
			int num = e - '0';
			cur = max(cur, num);
		}
		b[i] = cur;
	}
	b.push_back(INF);

	vector<int> stk;
	for (int i = 0; i <= n; i ++) {
		while (stk.size() && b[stk.back()] < b[i]) {
			siz[stk.back()] = i - stk.back();
			stk.pop_back();
		}
		stk.push_back(i);
	}
	vector<SegmentTree> st(10);

	vector<i64> pre(n);
	pre[0] = a[0];
	for (int i = 1; i < n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}

	for (int i = 2; i < 10; i ++) {
		vector<int> tmp(n + 1);
		for (int j = 0; j < n; j ++) {
			tmp[j] = pre[j] % i;
		}
		st[i].init(n, i, tmp);
	}

	i64 ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		vector<array<int, 3>> v;
		for (int j = i; j < n; j += siz[j]) {
			v.push_back({b[j], j, j + siz[j] - 1});
			cnt ++;
		}
		for (auto [num, l, r] : v) {
			if (num == 1) {
				ans += (r - l + 1);
			} else {
				ans += st[num].query(l + 1, r + 1).cnt[0];
			}
		}
		for (int j = 2; j < 10; j ++) {
			st[j].modify(i + 1, n, (j - (a[i] % j)) % j);
		}
	}
	cout << ans << '\n';

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