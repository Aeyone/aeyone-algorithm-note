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
    int mx = 0;
};

struct Lazy{
    int add = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.mx = max(l.mx, r.mx);
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 	vector<int> arr;

    SegmentTree() {}
    SegmentTree(int _n, vector<int> &_arr) {
        init(_n, _arr);
    }

    void init(int _n, vector<int> &_arr){
        n = _n;
        arr = _arr;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n);
    }

    void apply(int p, int val, int siz){
        info[p].mx += val;
        lazy[p].add += val;
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
    
    void build(int p, int l, int r){
        if (l == r){
            info[p] = {arr[l]};
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
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
	vector<int> a(n + 1);
	vector<vector<int>> idx(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		idx[a[i]].push_back(i);
	}
	for(auto &v : idx) {
		reverse(v.begin(), v.end());
	}
	vector<int> tmp(n + 1), cnt(n + 1);
	for (int i = 1; i <= n; i ++) {
		cnt[a[i]] ++;
		if (cnt[a[i]] == 1) {
			tmp[i] = 1;
		}
		if (cnt[a[i]] == idx[a[i]].size()) {
			tmp[i] += -1;
		}
	}
	for (int i = 1; i <= n; i ++) {
		tmp[i] += tmp[i - 1];
	}
	SegmentTree st(n, tmp);
	tmp.assign(n + 1, 0);
	int pre = 0, suf = n - count(cnt.begin() + 1, cnt.end(), 0);
	int ans = 0;
	for (int i = 1; i <= n - 2; i ++) {
		pre += (tmp[a[i]] == 0);
		tmp[a[i]] ++;
		suf -= (tmp[a[i]] == cnt[a[i]]);
		idx[a[i]].pop_back();
		if (idx[a[i]].size()) {
			st.modify(i, idx[a[i]].back() - 1, -1);
		}
		ans = max(ans, pre + suf + st.query(i + 1, n).mx);
	}
	cout << ans << '\n';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}