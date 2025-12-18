#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string b;
	cin >> b;
	if(n == 1){
		cout << 0 << '\n';
		return;
	}
	vector<int> s1, s2;
	for(auto e : b){
		if(e == '0')
			s1.push_back(0);
		else
			s1.push_back(1);
	}
	s2 = s1;
	int c1 = 0, c2 = 0;
	bool ok = false;
	for(int i = 0; i < n - 1; i ++){
		if(i & 1){
			if(s1[i] != 0)
				s1[i] = 0, s1[i + 1] = !s1[i + 1], c1 ++;
		}else{
			if(s1[i] != 1)
				s1[i] = 1, s1[i + 1] = !s1[i + 1], c1 ++;
		}
	}
	if(s1[n - 1] != s1[n - 2])
		ok = true;
	else
		c1 = 0x3f3f3f3f;

	for(int i = 0; i < n - 1; i ++){
		if(i & 1){
			if(s2[i] != 1)
				s2[i] = 1, s2[i + 1] = !s2[i + 1], c2 ++;
		}else{
			if(s2[i] != 0)
				s2[i] = 0, s2[i + 1] = !s2[i + 1], c2 ++;
		}
	}
	if(s2[n - 1] != s2[n - 2])
		ok = true;
	else
		c2 = 0x3f3f3f3f;

	if(ok)
		cout << min(c1, c2) << '\n';
	else
		cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}