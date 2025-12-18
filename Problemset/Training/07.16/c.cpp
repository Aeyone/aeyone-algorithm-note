#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	i64 x;
	cin >> x;
	x --;
	int len = s.size();
	while(x >= len)
		x -= (len --);

	int pos = 0, d = s.size() - len;
	while(d){
		if(pos < s.size() - 1){
			if(s[pos] > s[pos + 1]){
				int p = pos;
				while(d && p >= 0 && (s[p] == '&' || s[p] > s[pos + 1])){
					if(s[p] != '&')
						s[p] = '&', d --;
					p --;
				}
			}
			pos ++;
		}else{
			s.pop_back();
			pos --, d --;
		}
	}
	string res;
	for(auto e : s)
		if(e != '&')
			res += e;
	cout << res[x];
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}