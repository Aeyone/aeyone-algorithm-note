#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto check = [&](string str)->i64{
		i64 res = 0;
		priority_queue<int, vector<int>, greater<int>> ha, hb;
		for(int i = 0; i < 2 * n; i ++){
			if(s[i] == 'A')
				ha.push(i);
			else
				hb.push(i);
		}
		for(int i = 0; i < 2 * n; i ++){
			if(i & 1){
				int u = hb.top();
				hb.pop();
				if(u > i){
					ha.pop();
					ha.push(u);
					res += (u - i);
				}
			}else{
				int u = ha.top();
				ha.pop();
				if(u > i){
					hb.pop();
					hb.push(u);
					res += (u - i);
				}
			}
		}
		return res;
	};
	i64 ans = check(s);
	for(auto &e : s){
		if(e == 'A')
			e = 'B';
		else
			e = 'A';
	}
	ans = min(ans, check(s));
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}