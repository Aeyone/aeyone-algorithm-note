#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s.back() != '0'){
		cout << "NO" << '\n';
		return;
	}
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		if(s[i] == '1'){
			cnt ++;
		}else if(cnt == 1){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}