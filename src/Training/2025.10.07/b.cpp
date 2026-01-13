#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll
/*
分类讨论:
	LLL->分裂			LRL->合并
	LLR->扩充，向前		LRR->扩充，向后
	RLL->无影响			RRL->无影响
	RLR->合并			RRR->分裂
*/
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	vector<vector<int>> stMX(n, vector<int>(22)), stMN(n, vector<int>(22));
	for(int i = 0; i < n; i ++){
		stMX[i][0] = stMN[i][0] = a[i];
	}
	for(int p = 1; n >> p > 0; p ++){
		for(int i = 0; i + (1 << p) <= n; i ++){
			stMX[i][p] = max(stMX[i][p - 1], stMX[i + (1 << (p - 1))][p - 1]);
			stMN[i][p] = min(stMN[i][p - 1], stMN[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->bool{//查询区间l~r是否有l~r的所有数
		int d = log2(r - l + 1);
		int mx = max(stMX[l][d], stMX[r - (1 << d) + 1][d]);
		int mn = min(stMN[l][d], stMN[r - (1 << d) + 1][d]);
		return (mn != (l + 1) || mx != (r + 1));
	};
	set<pair<int, int>> seg;
	for(int l = 0, r = 0; l < n; l = r){
		while(s[r] == s[l]){//找到第一个不是'R'的位置
			r ++;
		}
		int ll = r;
		while(r < n && s[r] == s[ll]){//找到区间右端点的后一个位置
			r ++;
		}
		seg.insert({l, r - 1});
	}
	int cnt = 0;
	for(auto [x, y] : seg){
		cnt += query(x, y);
	}
	auto find = [&](int idx)->array<int, 2>{
		auto it = --seg.lower_bound({idx, inf});
		array<int, 2> res = {it->first, it->second};
		seg.erase(it);
		return res;
	};
	while(q --){
		int x;
		cin >> x;
		x --;
		if(s[x] == 'R'){
			if(s[x - 1] == 'L' && s[x + 1] == 'L'){
				array<int, 2> L = find(x - 1), R = find(x + 1);
				cnt -= (query(L[0], L[1]) + query(R[0], R[1]) - query(L[0], R[1]));
				seg.insert({L[0], R[1]});
			}
			if(s[x - 1] == 'L' && s[x + 1] == 'R'){
				array<int, 2> L = find(x - 1), R = find(x + 1);
				cnt -= (query(L[0], L[1]) + query(R[0], R[1]) - query(L[0], L[1] + 1) - query(R[0] + 1, R[1]));
				seg.insert({L[0], L[1] + 1});
				seg.insert({R[0] + 1, R[1]});
			}
			if(s[x - 1] == 'R' && s[x + 1] == 'R'){
				array<int, 2> cur = find(x);
				cnt -= (query(cur[0], cur[1]) - query(cur[0], x) - query(x + 1, cur[1]));
				seg.insert({cur[0], x});
				seg.insert({x + 1, cur[1]});
			}
			s[x] = 'L';
		}else{
			if(s[x - 1] == 'L' && s[x + 1] == 'L'){
				array<int, 2> cur = find(x);
				cnt -= (query(cur[0], cur[1]) - query(cur[0], x - 1) - query(x, cur[1]));
				seg.insert({cur[0], x - 1});
				seg.insert({x, cur[1]});
			}
			if(s[x - 1] == 'L' && s[x + 1] == 'R'){
				array<int, 2> L = find(x - 1), R = find(x + 1);
				cnt -= (query(L[0], L[1]) + query(R[0], R[1]) - query(L[0], L[1] - 1) - query(R[0] - 1, R[1]));
				seg.insert({L[0], L[1] - 1});
				seg.insert({R[0] - 1, R[1]});
			}
			if(s[x - 1] == 'R' && s[x + 1] == 'R'){
				array<int, 2> L = find(x - 1), R = find(x + 1);
				cnt -= (query(L[0], L[1]) + query(R[0], R[1]) - query(L[0], R[1]));
				seg.insert({L[0], R[1]});
			}
			s[x] = 'R';
		}
		if(cnt == 0){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}