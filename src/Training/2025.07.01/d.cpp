#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, m;
	cin >> n >> k >> m;
	string s;
	cin >> s;
	vector<int> vis(26);
	int c = 0, sum = 0;
	string res;
	char x = '&';
	for(int i = 0; i < m; i ++){
		if(!vis[s[i] - 'a'] && s[i] - 'a' < k){
			vis[s[i] - 'a'] ++, sum ++;
			x = s[i];
		}
		
		if(sum && sum % k == 0){
			fill(vis.begin(), vis.end(), 0);
			c ++;
			sum = 0;
			res += x;
		}
	}
	if(c >= n){
		cout << "YES" << '\n';
		return;
	}
	cout << "NO" << '\n';
	for(int i = 0; i < k; i ++)
		if(!vis[i])
			x = 'a' + i;
	res += x;
	while(res.size() < n)
		res += 'a';

	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}