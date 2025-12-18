#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	int l = 0;
	bool ok = false;
	if(s == "-0"){
		cout << "-10" << '\n';
		return;
	}
	if(s[0] != '-'){
		while(l < s.size()){
			if(s[l] == '0'){
				cout << '1';
				ok = true;
				break;
			}else
				cout << s[l ++];
		}
		while(l < s.size())
			cout << s[l ++];
	}else{
		cout << s[l ++];
		while(l < s.size()){
			if(s[l] != '1' && s[l] != '0'){
				cout << '1';
				ok = true;
				break;
			}else
				cout << s[l ++];
		}
		while(l < s.size())
			cout << s[l ++];
	}
	if(!ok)
		cout << '1';
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