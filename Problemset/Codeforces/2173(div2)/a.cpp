#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cnt = 0;
	for(int l = 0, r = 0; l < n; l = r){
		if(s[l] == '0'){
			r ++;
			cnt ++;
			continue;
		}else{
			int mx = l + k + 1;
			while(r < n && r < mx){
				r ++;
				if(s[r] == '1'){
					mx = r + k + 1;
				}
			}
		}
	}
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}