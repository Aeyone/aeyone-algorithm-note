#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		res[i] = i + 1;
	}
	bool ok = true;
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		if(s[i] == '0'){
			cnt ++;
		}else{
			ok &= (cnt == 0 || cnt >= 2);
			for(int j = 1; j <= cnt / 2; j ++){
				swap(res[i - j], res[i - cnt - 1 + j]);
			}
			cnt = 0;
		}
	}
	ok &= (cnt == 0 || cnt >= 2);
	for(int j = 1; j <= cnt / 2; j ++){
		swap(res[n - j], res[n - cnt - 1 + j]);
	}
	if(ok){
		cout << "YES" << '\n';
		for(auto e : res){
			cout << e << ' ';
		}
		cout << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}