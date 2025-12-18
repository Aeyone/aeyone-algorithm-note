#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		a[i] += (i + 1);
		mp[-a[i]] ++;
	}
	for(auto &[e, c] : mp){
		int cur = -e, x = c, tot = 0;
		while(x --){
			tot ++, cur --;
			if(mp.find(-cur) != mp.end()){
				x += mp[-cur];
				mp.erase(-cur);
			}
		}
		c = tot;
	}
	for(auto [e, c] : mp){
		int cur = -e;
		while(c --){
			cout << cur -- << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}