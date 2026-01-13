#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//奇葩题
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "R" + s + "L";
	vector<int> res(n + 1);
	for(int l = 1, r = 2; l <= n; l = r, r ++){
		while(r <= n && s[r - 1] != s[r]){
			r ++;
		}
		for(int i = l; i < r; i ++){
			res[i] = r - l + 1;
		}
	}
	for(int i = 0; i <= n; i ++){
		if(s[i] == 'R' && s[i + 1] == 'L'){
			cout << "1" << ' ';
			continue;
		}
		if(s[i] == 'L'){
			cout << res[i] << ' ';
		}else{
			cout << res[i + 1] << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}