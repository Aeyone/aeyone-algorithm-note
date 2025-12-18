#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	while(q --){
		string t;
		int a;
		cin >> t;
		cin >> a;
		a --;
		vector<int> d;
		int len = 0;
		for(int i = a, j = 0; j < t.size(); j ++, i ++){
			if(s[i] == t[j])
				len ++;
			else{
				if(len)
					d.push_back(len);
				len = 0;
			}
		}
		if(len)
			d.push_back(len);
		i64 ans = 0;
		for(auto e : d)
			ans += (i64)(1 + e) * (e) / 2;
		cout << ans << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}