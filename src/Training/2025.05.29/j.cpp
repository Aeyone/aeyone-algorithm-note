#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	string res;
	bool ok = false;
	int idx = 0;
	for(int i = 1; i < s.size() - 2; i ++){
		if(s.substr(i, 3) == "dot" && i < s.size() - 3){
			res += s.substr(idx, i - idx) + ".";
			idx = i + 3;
		}
		if(s.substr(i, 2) == "at" && !ok){
			res += s.substr(idx, i - idx) + "@";
			ok = true;
			idx = i + 2;
		}
	}
	res += s.substr(idx, s.size() - idx);
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