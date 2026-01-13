#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;
void solve() {
	string s;
	cin >> s;

	bool ok = true;
	int len = 0, idx1 = 1, idx0 = inf;
	for(auto e : s){
		if(e == '+'){
			len ++;
		}
		if(e == '-'){
			len --;
			idx1 = min(len, idx1);
			if(len < idx0)
				idx0 = inf;
		}
		
		if(e == '1'){
			ok &= (len < idx0);
			idx1 = max(1, len);
		}
		if(e == '0'){
			ok &= (len > idx1 && len > 1);
			if(idx0 == inf)
				idx0 = len;
		}
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}