#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	bool ok = false;
	while(n --){
		string s;
		cin >> s;
		ok |= (s == "and" || s == "not" || s == "that" || s == "the" || s == "you");
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}