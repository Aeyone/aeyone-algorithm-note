#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	if(s.front() == '@' || s.back() == '@' || !count(s.begin(), s.end(), '@')){
		cout << "No solution" << '\n';
		return;
	}
	vector<string> a;
	int hh = 0, last = -100;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == '@'){
			if(i - last <= 2){
				cout << "No solution" <<'\n';
				return;
			}
			last = i;
			a.push_back(s.substr(hh, i - hh + 2));
			hh = i + 2;
		}
	}
	a.back() += s.substr(hh, s.size() - hh);
	for(int i = 0; i < a.size(); i ++){
		cout << a[i];
		if(i != a.size() - 1)
			cout << ',';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}