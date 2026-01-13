#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> g1(n), g2(n);
	vector<int> in(n), out(n);
	for(int i = 0; i < n - 1; i ++){
		if(s[i] == 'R'){
			g1[i].push_back(i + 1);//小于关系
			g2[i + 1].push_back(i);//大于关系
			in[i + 1] ++, out[i] ++;
		}else{
			g1[i + 1].push_back(i);
			g2[i].push_back(i + 1);
			in[i] ++, out[i + 1] ++;
		}
	}
	vector<int> l(n, 1), r(n);
	queue<int> q;
	for(int i = 0; i < n; i ++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto v : g1[u]){
			l[v] += l[u];
			if(-- in[v] == 0){
				q.push(v);
			}
		}	
	}
	for(int i = 0; i < n; i ++){
		if(!out[i]){
			q.push(i);
		}
	}
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto v : g2[u]){
			r[v] += r[u] + 1;
			if(-- out[v] == 0){
				q.push(v);
			}
		}	
	}
	vector<int> ans(n + 2);
	for(int i = 0; i < n; i ++){
		r[i] = n - r[i];
		ans[l[i]] ++, ans[r[i] + 1] --;  
	}
	for(int i = 1; i <= n; i ++){
		ans[i] = ans[i - 1] + ans[i];
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}