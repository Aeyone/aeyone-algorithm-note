#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	while(q --){
		int x;
		cin >> x;
		if(count(s.begin(), s.end(), 'B') == 0){
			cout << x << '\n';
			continue;
		}
		int t = 0;
		while(x > 0){
			if(s[t % n] == 'A'){
				x --;
			}else{
				x >>= 1;
			}
			t ++;
		}
		cout << t << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}