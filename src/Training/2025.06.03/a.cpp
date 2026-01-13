#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	int x;
	cin >> x;
	int n = s.size();
	string res(n, '?');
	for(int i = 0; i < n; i ++){
		int l = i - x, r = i + x;
		if(s[i] == '0'){
			if(l >= 0)
				res[l] = '0';
			if(r < n)
				res[r] = '0';
		}
	}
	for(int i = 0; i < n; i ++){
		int l = i - x, r = i + x;
		if(s[i] == '0')
			continue;
		if(l >= 0){
			if(res[l] == '?' || res[l] == s[i])
				res[l] = s[i];
			else if(r < n && res[r] == '?')
				res[r] = s[i];
			else{
				cout << -1 << '\n';
				return;
			}
		}else if(r < n && res[r] == '?')
			res[r] = s[i];
		else{
			cout << -1 << '\n';
			return;
		}
	}
	for(auto &e : res)
		e = (e == '?' ? '1' : e);
	cout << res << '\n';
}

signed main(){
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}