#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//赤石模拟
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> str(n);
	for(int i = 0; i < n; i ++){
		cin >> str[i];
	}
	vector<array<int, 2>> res;
	int ans = -1, siz = 0, L = 0;
	for(int l = 0, r = 0; l < s.size(); l ++){
		for(int i = 0; i < n; i ++) if(l + str[i].size() - 1 < s.size()){
			bool ok = true;
			for(int j = 0; j < str[i].size(); j ++){
				ok &= (s[l + j] == str[i][j]);
			}
			if(ok && l + str[i].size() - 1 >= L + siz){//盖过的染色区域(l + SIZE - 1)最起码要比r远
				ans = i;
				L = l;
				siz = str[i].size();
			}
		}
		if(l < r){
			continue;
		}
		if(ans != -1){
			res.push_back({ans + 1, L + 1});
			r = L + siz;
			ans = -1, siz = 0, L = r;
		}else{
			cout << -1 << '\n';
			return;
		}
	}
	cout << res.size() << '\n';
	for(auto [a, b] : res){
		cout << a << ' ' << b << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}