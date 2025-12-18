#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	stack<char> stk;
	for(int i = 0; i < n; i ++){
		if(stk.size() == 0){
			stk.push(s[i]);
			continue;
		}
		int t = 0, sign = 0;
		if(stk.top() < 'a')
			t = stk.top() - 'A';
		else
			t = stk.top() - 'a', sign = 1;

		int now = 0, flag = 0;
		if(s[i] < 'a')
			now = s[i] - 'A';
		else
			now = s[i] - 'a', flag = 1;

		if(flag ^ sign){
			stk.push(s[i]);
			continue;
		}
		if(!sign){
			if(25 - now == t && now < t){
				// cout << stk.top() << ' ' << s[i] << '\n';
				stk.pop();
			}else
				stk.push(s[i]);
		}else{
			if(25 - t == now && now > t){
				// cout << stk.top() << ' ' << s[i] << '\n';
				stk.pop();
			}else
				stk.push(s[i]);

		}
	}
	// while(stk.size()){
	// 	int x= stk.top();
	// 	cout << (char)x << ' ';
	// 	stk.pop();
	// }
	cout << stk.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}