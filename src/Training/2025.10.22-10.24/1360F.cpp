#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//观察力惊人，答案其实就是已知字符串中任意一个字母替换或者不动。
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	auto check = [&](string x, string y)->int{
		int cnt = 0;
		for(int i = 0; i < x.size(); i ++){
			cnt += (x[i] != y[i]);
		}
		return cnt;
	};
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			string s = a[i];
			for(int p = 0; p < 26; p ++){
				s[j] = 'a' + p;
				bool ok = true;
				for(auto e : a){
					ok &= (check(s, e) <= 1);
				}
				if(ok){
					cout << s << '\n';
					return;
				}
			}
		}
	}
	cout << -1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}