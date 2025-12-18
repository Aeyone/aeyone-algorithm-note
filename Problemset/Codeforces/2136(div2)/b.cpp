#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int len = 0, mx = 0, idx = 1;
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		if(s[i] == '1')
			res[i] = idx ++,len ++;
		else
			mx = max(mx, len), len = 0;
	}
	mx = max(mx, len);
	if(mx >= k){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n; i ++){
		if(s[i] == '0')
			cout << idx ++ << ' ';
		else
			cout << res[i] << ' ';
	}
	cout << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}