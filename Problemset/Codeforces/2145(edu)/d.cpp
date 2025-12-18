#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll
vector<vector<vector<vector<int>>>> f(40, vector<vector<vector<int>>>(500, vector<vector<int>>(31)));
vector<int> Q = {0};

void init(){
	for(int q = 1; q * (q - 1) / 2 <= 500; q ++){
		Q.push_back(q * (q - 1) / 2);
	}
	f[1][0][0] = {0};
	for(int i = 2; i < Q.size(); i ++){
		f[i] = f[i - 1];
		for(int v = Q[i]; v <= 500; v ++){
			for(int s = i; s <= 30; s ++){
				for(int c = 1; c * Q[i] <= v && c * i <= s; c ++){
					if(f[i - 1][v - c * Q[i]][s - c * i].size() == 0){
						continue;
					}
					f[i][v][s] = f[i - 1][v - c * Q[i]][s - c * i];
					for(int C = 0; C < c; C ++){
						f[i][v][s].push_back(i);
					}
				}
			}
		}
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	k = n * (n + 1) / 2 - k;
	k -= n;
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	if(k == 0 || k == n * (n - 1) / 2){
		if(k == 0){
			reverse(a.begin(), a.end());
		}
		for(auto e : a){
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}
	int idx = -1;
	for(int i = 0; i <= n; i ++){
		if(f[Q.size() - 1][k][i].size() == 0){
			continue;
		}
		idx = i;
	}
	if(idx == -1){
		cout << 0 << '\n';
		return;
	}
	reverse(a.begin(), a.end());
	int l = 0, r = 0;
	for(auto e : f[Q.size() - 1][k][idx]){
		r += e;
		reverse(a.begin() + l, a.begin() + r);
		l = r;
	}
	for(auto e : a){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	init();
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}