#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
using i64 = long long;

struct Info{
    i64 mn = INFLL;     //最小值
    i64 mn2 = INFLL;    //次小值
    i64 sum = 0;        //区间和
    int cnt = 0;
    int len = 0;
};

struct Lazy{//由于需要在第二个剪枝的时候只对最小值进行加，而次小值不需要，因此需要两个懒标记
    i64 add = 0;        //最小值的懒操作
    i64 otherAdd = 0;   //其他值的懒操作
};

Info operator+(const Info &l, const Info &r){
	Info res;
	res.len = l.len + r.len;
    res.sum = l.sum + r.sum;
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

    void init(int _n, vector<i64> &arr) {
        n = _n;
        info.assign(n << 2, Info(INFLL, INFLL, false));
        lazy.assign(n << 2, Lazy());
        build(1, 1, n, arr);
    }
    //对i节点进行+v的懒操作
    void applyAdd(int p, i64 val1, i64 val2) {
        info[p].sum += val1 * info[p].cnt + val2 * (info[p].len - info[p].cnt);
        info[p].mn += val1;
        info[p].mn2 += (info[p].mn2 == INFLL ? 0 : val2);
        lazy[p].add += val1;
        lazy[p].otherAdd += val2;
    }

    void down(int p) {
        i64 mn = min(info[2 * p].mn, info[2 * p + 1].mn);
        if(info[2 * p].mn == mn) {//左儿子存在最小
        	applyAdd(2 * p, lazy[p].add, lazy[p].otherAdd);
        }else{
        	applyAdd(2 * p, lazy[p].otherAdd, lazy[p].otherAdd);
        }
        if(info[2 * p + 1].mn == mn) {//右儿子存在最小
        	applyAdd(2 * p + 1, lazy[p].add, lazy[p].otherAdd);
        }else{
        	applyAdd(2 * p + 1, lazy[p].otherAdd, lazy[p].otherAdd);
        }
        lazy[p].otherAdd = lazy[p].add = 0;
    }
    //回溯，更新i的值
    void up(int p) {
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
    i64 setmax(int p, int l, int r, int L, int R, int k){
        if(L > r || R < l || info[p].mn > k){   //第一个剪枝：最小值大于k不操作
            return 0;
        }
        i64 res = 0;
        if(L <= l && r <= R && info[p].mn2 > k){//第二个剪枝：l~r被ql~qr完全包含时，且次小值大于k，只需要对最小值添加懒标记
        	res += (k - info[p].mn) * info[p].cnt;
        	applyAdd(p, k - info[p].mn, 0);
        }else{                                  //暴力下发过程
            int mid = (l + r) / 2;
            down(p);
            res += setmax(2 * p, l, mid, L, R, k);
            res += setmax(2 * p + 1, mid + 1, r, L, R, k);
            up(p);
        }
        return res;//统计累计上升的总和
    }
    //1-based
    void modify(int L, int R, int val){ 
        modify(1, 1, n, L , R , val);
    }
    i64 setmax(int L, int R, int k){
        return setmax(1, 1, n, L, R, k);
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
		res -= st.setmax(l, r, 0);
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