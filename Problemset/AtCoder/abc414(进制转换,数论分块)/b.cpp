#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; i ++){
		char c;
		i64 cnt;
		cin >> c >> cnt;
		if(s.size() + cnt <= 100){
			while(cnt)
				s += c, cnt --;
		}else{
			cout << "Too Long" << '\n';
			return;
		}
	}
	cout << s << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}