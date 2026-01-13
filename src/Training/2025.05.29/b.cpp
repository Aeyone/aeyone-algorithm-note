#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	string res;
	for(int i = 0; i < s.size();){
		if(s[i] != '.'){
			string tmp = s.substr(i, 2);
			if(tmp == "-.")
				res += "1";
			else
				res += "2";
			i += 2;
		}
		else{
			res += "0";
			i ++;
		}
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}