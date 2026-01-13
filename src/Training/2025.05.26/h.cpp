#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	for(auto &e : s1)
		if(e != '0'){
			swap(e, s1.front());
			break;
		}
	if(s1 != s2)
		cout << "WRONG_ANSWER\n";
	else
		cout << "OK\n";
	
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}