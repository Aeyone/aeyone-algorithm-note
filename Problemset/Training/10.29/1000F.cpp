#pragma GCC optimize (3)
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
int unit; //块大小
inline getBlock(int x){
	return x / unit;
}
struct Query {
  int l, r, id;
  bool operator<(const Query &x) const {//奇偶排序
  	int a = getBlock(l), b = getBlock(x.l);
    if (a != b){
    	return l < x.l;
    }
    if(a & 1){
    	return r < x.r;
    }else{
	    return r > x.r;
    }
  }
};

void solve() {//莫队
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int mx = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int q;
	cin >> q;
	vector<Query> que(q);
	for(int i = 0; i < q; i ++){
		cin >> que[i].l >> que[i].r;
		que[i].id = i;
	}
	unit = 990;
	sort(que.begin(), que.end());

	vector<int> ans(q), cnt(mx + 1), s = {0}, idx(mx + 1);
	cnt[0] = 1;
	auto add = [&](int u)->void{
		int x = a[u];
		cnt[x] ++;
		if(cnt[x] == 1){
			s.push_back(x);
			idx[x] = s.size() - 1;
		}
		if(cnt[x] == 2){
			s[idx[x]] = s.back();
			idx[s.back()] = idx[x];
			s.pop_back();
			idx[x] = 0;
		}
	};
	auto del = [&](int u)->void{
		int x = a[u];
		cnt[x] --;
		if(cnt[x] == 1){
			s.push_back(x);
			idx[x] = s.size() - 1;
		}
		if(cnt[x] == 0){
			s[idx[x]] = s.back();
			idx[s.back()] = idx[x];
			s.pop_back();
			idx[x] = 0;
		}
	};

	int l = 1, r = 0;
	for(register int i = 0; i < q; i ++){
		auto &[L, R, id] = que[i];
		while(l > L) add(-- l);
		while(r < R) add(++ r);
		while(l < L) del(l ++);
		while(r > R) del(r --);
		ans[id] = s.back();
	}
	for(auto e : ans){
		cout << e << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}