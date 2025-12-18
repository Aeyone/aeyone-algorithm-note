#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	bool ok = false;
	map<char, bool> vis;
	vis[s[0]] = vis[s[n - 1]] = true;
	for(int i = 1, j = n - 2; i <= j; i ++, j --){
		if(!vis[s[i]]){
			vis[s[i]] = true;
		}else{
			ok = true;
			break;
		}

		if(i == j)
			break;

		if(!vis[s[j]])
			vis[s[j]] = true;
		else{
			ok = true;
			break;
		}
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}