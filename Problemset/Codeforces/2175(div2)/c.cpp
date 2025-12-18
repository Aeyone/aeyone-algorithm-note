#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	string s, t;
	cin >> s >> t;
	vector<int> cnt(26);
	for(auto e : t){
		cnt[e - 'a'] ++;
	}
	bool ok = true;
	for(auto e : s){
		cnt[e - 'a'] --;
		ok &= (cnt[e - 'a'] >= 0);
	}
	if(!ok){
		cout << "Impossible" << '\n';
		return;
	}
	vector<string> lis(26);
	int n = s.size();
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && s[r] <= s[l]){
			r ++;
		}
		lis[s[l] - 'a'] = s.substr(l, r - l);
	}
	string res;
	for(int i = 0; i < 26; i ++){
		if(lis[i].size()){
			res += lis[i];
		}
		if(cnt[i] > 0){
			res += string(cnt[i], 'a' + i);
		}
	}
	cout << res << '\n';
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