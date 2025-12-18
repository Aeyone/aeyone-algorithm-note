#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int u = -1;
	string res;
	for(int i = 0; i < n - 1; i ++){
		if(s[i] > s[i + 1]){
			u = i;
			break;
		}
		res += s[i];
	}
	if(u == -1){
		cout << s << '\n';
		return;
	}
	int v = u + 1;
	while(v < n && s[u] >= s[v])
		res += s[v ++];

	res += s[u];
	while(v < n)
		res += s[v ++];

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