#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
using i64 = long long;

struct Info{//主要信息
    i64 mn = INFLL;
    i64 mn2 = INFLL;
    int cnt = 0;
    int len = 0;
};

struct Lazy{//懒信息
    i64 add = 0;
    i64 otherAdd = 0;
};

Info operator+(const Info &l, const Info &r){
	Info res;
	res.len = l.len + r.len;
	if(l.mn == r.mn){
		res.mn = l.mn;
		res.cnt = l.cnt + r.cnt;
		res.mn2 = min(l.mn2, r.mn2);
	}else if(l.mn < r.mn){
		res.mn = l.mn;
		res.cnt = l.cnt;
		res.mn2 = min(l.mn2, r.mn);
	}else{
		res.mn = r.mn;
		res.cnt = r.cnt;
		res.mn2 = min(l.mn, r.mn2);
	}
	return res;
}
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;

    SegmentTree() {}
    SegmentTree(int _n, vector<i64> &arr) {
        init(_n, arr);
    }

    void init(int _n, vector<i64> &arr){
        n = _n;
        info.assign(n << 2, Info(INFLL, INFLL, false));
        lazy.assign(n << 2, Lazy());
        build(1, 1, n,  arr);
    }
    //对i节点进行+v的懒操作
    void applyAdd(int p, i64 val1, i64 val2){
        info[p].mn += val1;
        info[p].mn2 += (info[p].mn2 == INFLL ? 0 : val2);
        lazy[p].add += val1;
        lazy[p].otherAdd += val2;
    }

    void down(int p){
        i64 tmp = min(info[2 * p].mn, info[2 * p + 1].mn);
        if(info[2 * p].mn == tmp){
        	applyAdd(2 * p, lazy[p].add, lazy[p].otherAdd);
        }else{
        	applyAdd(2 * p, lazy[p].otherAdd, lazy[p].otherAdd);
        }
        if(info[2 * p + 1].mn == tmp){
        	applyAdd(2 * p + 1, lazy[p].add, lazy[p].otherAdd);
        }else{
        	applyAdd(2 * p + 1, lazy[p].otherAdd, lazy[p].otherAdd);
        }
        lazy[p].otherAdd = lazy[p].add = 0;
    }
    //回溯，更新i的值
    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    //构建线段树 O(N)
    void build(int p, int l, int r, vector<i64> &arr){
        if (l == r){
            info[p] = {arr[l], INFLL, 1, 1};
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, arr);
            build(2 * p + 1, mid + 1, r, arr);
            up(p);//回溯更新info[i]
        }
    }
    void modify(int p, int l, int r, int L, int R, int val){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){//l~r被ql~qr完全包含时，进行懒操作，不用往下递归了
            applyAdd(p, val, val);
        }else{
            int mid = (l + r) / 2;
            down(p);//l~r不完全被ql~qr包含，懒信息下发
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);//回溯
        }
    }
    i64 query(int p, int l, int r, int L, int R){
        i64 res = 0;
        if(L > r || R < l || info[p].mn > 0){//第一个剪枝：最小值大于0不操作
            return res;
        }
        if(L <= l && r <= R && info[p].mn2 > 0 ){//第二个剪枝：l~r被ql~qr完全包含时，且次小值大于0，添加懒标记
        	res += info[p].mn * info[p].cnt;
        	applyAdd(p, -info[p].mn, 0);
        }else{
            int mid = (l + r) / 2;
            down(p);//l~r不完全被ql~qr包含，懒信息下发
            res += query(2 * p, l, mid, L, R);
            res += query(2 * p + 1, mid + 1, r, L, R);
            up(p);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, int val){ 
        if(L <= R){
            modify(1, 1, n, L , R , val);
        }
    }
    i64 query(int L, int R){
        if(L <= R){
            return query(1, 1, n, L , R );
        }
    }
};

void solve() {//吉如一线段树
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	SegmentTree st(n, a);
	int q;
	cin >> q;
	while(q --){
		int l, r, k;
		cin >> l >> r >> k;
		i64 res = 1ll * (r - l + 1) * k;
		st.modify(l, r, -k);
		res += st.query(l, r);
		cout << res << '\n';
	}
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